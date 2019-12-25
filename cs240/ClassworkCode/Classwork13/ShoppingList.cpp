




int main(){

vector<string> shop;
shop.push_back("eggs");
shop.push_back("milk");
shop.push_back("sugar");
shop.push_back("chocolate");
shop.push_back("flour");
shop.pop_back();
shop.push_back("coffee");



for(vector<string> ::iterator it = shop.begin(); it != shop.end(); it++)
{
  if(*it == "sugar") *it = "honey";
}



for(vector<string> ::iterator it = shop.begin(); it != shop.end(); it++)
{

if(*it == "milk")
  it = shop.erase(it);

}


for(vector<string> ::iterator it = shop.begin(); it != shop.end(); it++)
{
cout << *it << endl;
}


}
