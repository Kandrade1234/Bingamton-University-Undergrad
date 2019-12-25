'use strict';

const assert = require('assert');
const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs');
const querystring = require('querystring');

const Mustache = require('./mustache');
const widgetView = require('./widget-view');

const STATIC_DIR = 'statics';
const TEMPLATES_DIR = 'templates';

function serve(port, model, base='') {
  //@TODO

	const app = express();
	app.locals.port = port;
	app.locals.model = model;
	app.locals.base = base;
	app.locals.mustache = new Mustache();
	process.chdir(__dirname);
	app.use(base, express.static(STATIC_DIR));
	setupTemplates(app);
	setupRoutes(app);
	app.listen(port, function(){
		console.log(`listening on port ${port}`);
	});
}


module.exports = serve;
const ROUTES = {
	sts: `sensor-type-search.html`,
	sta: `sensor-type-add.html`,
	ss: `sensor-search.html`,
	sa: `sensor-add.html`,
};

function setupRoutes(app){
	const base = app.locals.base;
	app.get(`${base}/${ROUTES.sts}`, doSearch(app, true));
	app.get(`${base}/${ROUTES.sta}`, doAdd(app,'', true));
	app.post(`${base}/${ROUTES.sta}`, bodyParser.urlencoded({extended:true}),
		doAdd(app,'submit', ''));
	app.get(`${base}/${ROUTES.ss}`, doSearch(app,false));
	app.get(`${base}/${ROUTES.sa}`, doAdd(app,'',false));
	app.post(`${base}/${ROUTES.sa}`, bodyParser.urlencoded({extended:true}),
		doAdd(app, 'submit', false));

	app.use(doErrors(app)); //must be last

}


/*******************Error**********************/
const OK = 200;
const CREATED = 201;
const BAD_REQUEST = 400;
const NOT_FOUND = 404;
const CONFLICT = 409;
const SERVER_ERROR = 500;

function doErrors(app){
	return async function(err, req, res, next){
		res.status(SERVER_ERROR);
		res.send(app.locals.mustache.render(`errors`, {msg: err.message}));
		console.error(err);
	}
}

/****************Action Routines***************/

function doAdd(app, submit, type){
	return errorWrap(async function(req, res){
		var error = [];

	let opts;
	if(type){
		if(submit){
			opts = {	id: {value: req.body.id},
					modelNumber: {value: req.body.modelNumber},
					manufacturer: {value: req.body.manufacturer},
					quantity: {value: req.body.quantity},
					limits: {value:{min: req.body.limits.min, max: req.body.limits.max}}
				};
		}
		else {
			opts = {	id: {value: ''},
					modelNumber: {value: ''},
					manufacturer: {value: ''},
					quantity: {value: ''},
					limits: {value: ''}
				};
		}
	}
	else{
		if(submit){
			opts = {	id: {value: req.body.id},
					model: {value: req.body.model},
					period: {value: req.body.period},
					expected: {value: {min: req.body.expected.min, max: req.body.expected.max}}
			};

		}
		else{
			opts = {	id: {value: ''},
					model: {value: ''},
					period: {value: ''},
					expected: {value: {mind:'', max: ''}}
			};


		}
	}

	let valid = true;
	if(submit){
		req.body.unit = 12;
		if(valid){
			let str = querystring.stringify(getNonEmptyValues(req.body));
			let url;
			let resu;
			try{
				if(type){
					if(req.body.limits.min !== '' && req.body.limits.max !== '')
						str = str.replace ('limits=', 'limits[min]=' + req.body.limits.min + '&limits[max]=' + req.body.limits.max);
					url = app.locals.model.baseUrl + '/sensor-types';
				}
				else{
					if(req.body.expected.min !== '' && req.body.expected.max !== '')
						str = str.replace ('expected=', 'expected[min]=' + req.body.expected.min + '&expected[max]=' + req.body.expected.max);
					url = app.locals.model.baseUrl + '/sensors';
				}
				if(str.length)
					url = url + '?';
				resu = await axios.post(url + str);
			}
			catch(err){
				valid = false;
				for(const e of err.response.data.errors){
					let widget = e.widget;
					if(e.code === 'MISSING'){
						if(widget ==='id'){
							if(type) opts.id.error = "A value for 'Sensor Type ID' must be provided.";
							else opts.id.error = "A value for 'Sensor ID' must be provided.";
						}
						if(widget === 'model' || widget === 'modelNumber' || widget === 'manufacturer' || widget === 'quantity' || widget === 'period')
							opts[widget].error = `A value for ${widget} must be provided.`;
						if(widget === 'limits')
							opts.limits.error = "A value for each field of 'limits' must be provided.";
						if(widget === 'expected')
							opts.expected.error = "A value for each field of 'expected' must be provided."

					}
					if(e.code === "TYPE"){
						if(widget === 'limits.min')
                                                        opts.limits.error = "Min value must be a number.";
                                                if(widget === 'limits.max')
                                                        opts.limits.error = "Max value must be a number.";
						if(widget === 'expected.min' || widget === 'expected.max')
							opts.expected.error = "both expected values must be numbers.";
					}
					else if(e.code === 'INTERNAL'){
						error.push(e.message);
					}
					else if(e.code === 'X_ID'){
						error.push('Not found');
					}
				}

			}
		}
	}

	let mod;
	let temp;
	let search = [];
	if(submit && valid){
		if(type) return res.redirect('/sensor-type-search.html?id=' + req.body.id);
		else return res.redirect('/sensor-search.tml?id=' + req.body.id);
	}
	else{
		if(type){
			search.push({id: '1', name: 'id', type: 'text', class: 'tst-sensor-type-id', label: 'Sensor Type ID *', value: 'hello'});
			search.push({id: '2', name: 'modelNumber', type: 'text', class: 'tst-model-number', label: 'Model Number *', value: req.query.modelNumber});
			search.push({id: '3', name: 'manufacturer', type: 'text', class: 'tst-manufacturer', label: 'Manufacturer *', value: req.query.manufacturer});
			search.push({id: '4', name: 'quantity', type: 'select', class: 'tst-quantity', label: 'Measure *', choices: {'': 'Select', temperature: 'Temperature', preassure: 'Preassure', flow: 'Flow Rate', humidity: 'Humidity'}, value: req.query.quantity});
			search.push ({id: '5', name: 'limits', type: 'interval', class: 'numeric interval', label: 'Limits *'});
		temp = 'sensor-type-add';
		}
		else{
			search.push({id: '1', name: 'id', type: 'text', class: 'tst-sensor-id', label: 'Sensor ID *', value: 'hello'});
			search.push({id: '2', name: 'model', type: 'text', class: 'tst-model', label: 'Model *', value: req.query.modelNumber});
			search.push({id: '3', name: 'period', type: 'text', class: 'tst-period numeric', label: 'Period *', value: req.query.manufacturer});
			search.push({id: '4', name: 'expected', type: 'interval', class: 'numeric interval', label: 'Expected Range *'});
			temp = 'sensor-add';
		}

	for(let i = 0; i < search.length; i++)
		search[i] = widgetView(search[i], opts[search[i].name]);

	var contain = [];
	mod = errorModel(app, search, contain);
	mod.errors = error;
	if(error.length > 0) mod.hasError = 1;
	}

	const html = doMustache(app, template, mod);
	res.send(html);

	});
};




/////////////////////
function doSearch(app, type){
	return async function(req, res){
		const submit = req.query !== undefined;
		let options = {};
		let rgx = /^[A-Za-z0-9-_]+$/;
		let rgxInt = /^[0-9]+$/;
		let errors = [];
		let results;
		if(type) {
			options = {	id: {value: req.query.id},
									modelNumber: {value: req.query.modelNumber},
									manufacturer: {value: req.query.manufacturer},
									quantity: {value: req.query.quantity},
				};
		}
		else{
			options = {	id: {value: req.query.id},
									model: {value: req.query.model},
									period: {value: req.query.period}
			};
		}

	if(submit){
		let valid = true;
		if(type){
			if(!rgx.test(req.query.id) && req.query.id.trim() !== '' ){
				options.id.error = "Sensor Type ID field can contain alphanumerics, '-' or '_'";
				valid = false;
			}
			if(!rgx.test(req.query.modelNumber) && req.query.modelNumber.trim() !== '' ){
				options.id.error = "Model Number field can contain alphanumerics, '-' or '_'";
				valid = false;
			}
			if(!rgx.test(req.query.manufacturer) && req.query.manufacturer.trim() !== '' ){
				options.id.error = "Manufacturer field can contain alphanumerics, '-' or '_'";
				valid = false;
			}
		}
		else{
			if(!rgx.test(req.query.id) && req.query.id.trim() !== '' ){
				options.id.error = "Sensor ID field can contain alphanumerics, '-' or '_'";
				valid = false;;
			}
			if(!rgx.test(req.query.model) && req.query.model.trim() !== '' ){
				options.model.error = "Model field can contain alphanumerics, '-' or '_'";
				valid = false;
			}
			if(!rgx.test(req.query.period) && req.query.period.trim() !== '' ){
				options.period.error = "Period field must be integer";
				valid = false;
			}
		}
		if(valid){
			const str = querystring.stringify(getNonEmptyValues(req.query));
			let url;
			try{
				if(type)
					url = app.locals.model.baseUrl + '/sensor-types';
				else
					url = app.locals.model.baseUrl + '/sensors';

				if(str.length > 0) url = url + '?';

				results = await axios.get(url + str);
			}
			catch(err){
				for(const e of err.response.data.errors){
					let widget = e.widget;
					if(widget === 'id'){
						if(e.code === 'NOT_FOUND'){
							errors.push("No Results Found")
						}
					}
				}
			}
		}

	}
	let mod, temp;
	var search = [];
	if(type){
		search.push({id: '1', name: 'id', type: 'text', class: 'tst-sensor-type-id', label: 'Sensor Type ID *', value: 'hello'});
		search.push({id: '2', name: 'modelNumber', type: 'text', class: 'tst-model-number', label: 'Model Number *', value: req.query.modelNumber});
		search.push({id: '3', name: 'manufacturer', type: 'text', class: 'tst-manufacturer', label: 'Manufacturer *', value: req.query.manufacturer});
		search.push({id: '4', name: 'quantity', type: 'select', class: 'tst-quantity', label: 'Measure *', choices: {'': 'Select', temperature: 'Temperature', preassure: 'Preassure', flow: 'Flow Rate', humidity: 'Humidity'}, value: req.query.quantity});
	temp = 'sensor-type-search';
	}
	else{
		search.push({id: '1', name: 'id', type: 'text', class: 'tst-sensor-id', label: 'Sensor ID *', value: 'hello'});
		search.push({id: '2', name: 'model', type: 'text', class: 'tst-model', label: 'Model *', value: req.query.modelNumber});
		search.push({id: '3', name: 'period', type: 'text', class: 'tst-period numeric', label: 'Period *', value: req.query.manufacturer});
		temp = 'sensor-search';
	}
	for(let i =0; i < search.length; i++) search[i] = widgetView(search[i], options[search[i].name]);
	mod = errorModel(app, search, errors);
	mod.error = error;
	if(errors.length>0) mod.hasErrors = 1;
	if(submit && results !== undefined){
		mod.results = results.data;
		mod.hasResults = 1;
		if(mod.results.hasOwnProperty('next')){
			let str = mod.results.next;
			let nextRef = str.substring(str.lastIndexOf("?")) + '&submit=search';
			mod.results.nextRef = nextRef;
		}
		if(mod.results.hasOwnProperty('prev')){
			let str = mod.results.prev;
			let prevRef = str.substring(str.lastIndexOf("?")) + '&submit=search'
			mod.results.prevRef = prevRef;
		}
	}
	const html = doMustache(app, temp, mod);
	res.send(html);
};
};





function errorModel(app, values={}, errors={}){
let widget = {id: '1', name: 'ih', label: 'test', type:'text'}

	return{
		base: app.locals.base,
		errors: errors._,
		widgets: values
	};
};

function getNonEmptyValues(values){
	const out = {};
	for(let p in values){
		if(p != 'submit' && values[p]) out[p] = values[p]
	}
return out;
};

function setupTemplates(app){
	app.templates = {};
	for(let f of fs.readdirSync(TEMPLATES_DIR)){
		const a = f.match(/^([\w\-]+)\.ms$/);
		if(!a) continue;
		try{
			app.templates[a[1]] = String(fs.readFileSync(`${TEMPLATES_DIR}/${f}`));
		}
		catch(err){
			console.error(`cannot read: ${f}: ${err}`);
			process.exit(1);
		}
	}
};
function errorWrap(handler){
	return async (req, res, next) =>{
		try{
			await handler (req, res, next);
		}
		catch(err){
			next(err);
		}
	};
}
function doMustache(app, templateID, view){
	const templates = {footer: app.templates.footer, widget: app.templates.widget};
	return mustache.render(app.templates[templateID], view, templates);
};
//@TODO
