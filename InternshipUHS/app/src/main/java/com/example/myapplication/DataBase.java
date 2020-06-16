package com.example.myapplication;
import java.util.*;

public class DataBase {
    List<List<String>> wordsArray;
    int listNum;

    /* This constructor takes the number of Lists that there are.
       The constructor will initialize the outer array
       for now it assumes the value is greater than zero
     */
    public DataBase(int size)
    {
        listNum = size;
        wordsArray = new ArrayList<List<String>>(listNum);
    }

    /* This function will initialize the inner array with a second array list(AKA a 2D matrix)
       will store 10 words in each list.....this can later be changed to add more modification/customization....
       a text file will make things easier.
       the reason on why i add words as im initializing is to make sure that the variable i is within bounds....
       just a sanity check.
     */
    public void initialize()
    {
        //making a 2d array so adding words can be easier.
        for(int i = 0; i < listNum; i++)  {
            wordsArray.add(new ArrayList<String>());

            //this isnt preety but for now it will do. until later optimization
            if (i == 0)
            {
                wordsArray.get(0).add("the");
                wordsArray.get(0).add("I");
                wordsArray.get(0).add("to");
                wordsArray.get(0).add("you");
                wordsArray.get(0).add("and");
                wordsArray.get(0).add("of");
                wordsArray.get(0).add("he");
                wordsArray.get(0).add("it");
                wordsArray.get(0).add("a");
                wordsArray.get(0).add("in");
            }
            if(i ==1)
            {
                wordsArray.get(1).add("was");
                wordsArray.get(1).add("for");
                wordsArray.get(1).add("said");
                wordsArray.get(1).add("on");
                wordsArray.get(1).add("his");
                wordsArray.get(1).add("they");
                wordsArray.get(1).add("that");
                wordsArray.get(1).add("but");
                wordsArray.get(1).add("she");
                wordsArray.get(1).add("had");
            }
            if(i == 2)
            {
                wordsArray.get(2).add("at");
                wordsArray.get(2).add("look");
                wordsArray.get(2).add("him");
                wordsArray.get(2).add("is");
                wordsArray.get(2).add("with");
                wordsArray.get(2).add("her");
                wordsArray.get(2).add("up");
                wordsArray.get(2).add("there");
                wordsArray.get(2).add("all");
                wordsArray.get(2).add("some");
            }
            if(i == 3)
            {
                wordsArray.get(3).add("out");
                wordsArray.get(3).add("we");
                wordsArray.get(3).add("as");
                wordsArray.get(3).add("am");
                wordsArray.get(3).add("be");
                wordsArray.get(3).add("then");
                wordsArray.get(3).add("have");
                wordsArray.get(3).add("little");
                wordsArray.get(3).add("go");
                wordsArray.get(3).add("down");
            }
            if(i == 4)
            {
                wordsArray.get(4).add("do");
                wordsArray.get(4).add("what");
                wordsArray.get(4).add("can");
                wordsArray.get(4).add("so");
                wordsArray.get(4).add("could");
                wordsArray.get(4).add("see");
                wordsArray.get(4).add("when");
                wordsArray.get(4).add("not");
                wordsArray.get(4).add("did");
                wordsArray.get(4).add("were");
            }
            if(i == 5)
            {
                wordsArray.get(5).add("get");
                wordsArray.get(5).add("my");
                wordsArray.get(5).add("them");
                wordsArray.get(5).add("would");
                wordsArray.get(5).add("like");
                wordsArray.get(5).add("me");
                wordsArray.get(5).add("one");
                wordsArray.get(5).add("will");
                wordsArray.get(5).add("this");
                wordsArray.get(5).add("yes");
            }
            if(i == 6)
            {
                wordsArray.get(6).add("big");
                wordsArray.get(6).add("now");
                wordsArray.get(6).add("went");
                wordsArray.get(6).add("first");
                wordsArray.get(6).add("are");
                wordsArray.get(6).add("no");
                wordsArray.get(6).add("come");
                wordsArray.get(6).add("came");
                wordsArray.get(6).add("if");
                wordsArray.get(6).add("ask");
            }
            if(i == 7)
            {
                wordsArray.get(7).add("very");
                wordsArray.get(7).add("ride");
                wordsArray.get(7).add("an");
                wordsArray.get(7).add("into");
                wordsArray.get(7).add("over");
                wordsArray.get(7).add("just");
                wordsArray.get(7).add("your");
                wordsArray.get(7).add("blue");
                wordsArray.get(7).add("black");
                wordsArray.get(7).add("red");
            }
            if(i == 8)
            {
                wordsArray.get(8).add("from");
                wordsArray.get(8).add("want");
                wordsArray.get(8).add("good");
                wordsArray.get(8).add("won't");
                wordsArray.get(8).add("any");
                wordsArray.get(8).add("how");
                wordsArray.get(8).add("about");
                wordsArray.get(8).add("know");
                wordsArray.get(8).add("around");
                wordsArray.get(8).add("has");
            }
            if(i == 9)
            {
                wordsArray.get(9).add("put");
                wordsArray.get(9).add("every");
                wordsArray.get(9).add("too");
                wordsArray.get(9).add("pretty");
                wordsArray.get(9).add("got");
                wordsArray.get(9).add("jump");
                wordsArray.get(9).add("take");
                wordsArray.get(9).add("green");
                wordsArray.get(9).add("where");
                wordsArray.get(9).add("four");
            }
            if(i == 10)
            {
                wordsArray.get(10).add("away");
                wordsArray.get(10).add("saw");
                wordsArray.get(10).add("find");
                wordsArray.get(10).add("white");
                wordsArray.get(10).add("by");
                wordsArray.get(10).add("after");
                wordsArray.get(10).add("us");
                wordsArray.get(10).add("well");
                wordsArray.get(10).add("here");
                wordsArray.get(10).add("why");
            }
            if(i == 11)
            {
                wordsArray.get(11).add("ran");
                wordsArray.get(11).add("under");
                wordsArray.get(11).add("let");
                wordsArray.get(11).add("brown");
                wordsArray.get(11).add("help");
                wordsArray.get(11).add("yellow");
                wordsArray.get(11).add("make");
                wordsArray.get(11).add("five");
                wordsArray.get(11).add("going");
                wordsArray.get(11).add("because");
            }
            if(i == 12)
            {
                wordsArray.get(12).add("walk");
                wordsArray.get(12).add("again");
                wordsArray.get(12).add("two");
                wordsArray.get(12).add("play");
                wordsArray.get(12).add("or");
                wordsArray.get(12).add("who");
                wordsArray.get(12).add("before");
                wordsArray.get(12).add("been");
                wordsArray.get(12).add("eat");
                wordsArray.get(12).add("may");
            }
            if(i == 13)
            {
                wordsArray.get(13).add("stop");
                wordsArray.get(13).add("cold");
                wordsArray.get(13).add("off");
                wordsArray.get(13).add("goes");
                wordsArray.get(13).add("three");
                wordsArray.get(13).add("six");
                wordsArray.get(13).add("seven");
                wordsArray.get(13).add("nine");
                wordsArray.get(13).add("eight");
                wordsArray.get(13).add("ten");
            }
            if(i == 14)
            {
                wordsArray.get(14).add("tell");
                wordsArray.get(14).add("long");
                wordsArray.get(14).add("much");
                wordsArray.get(14).add("try");
                wordsArray.get(14).add("keep");
                wordsArray.get(14).add("new");
                wordsArray.get(14).add("give");
                wordsArray.get(14).add("must");
                wordsArray.get(14).add("work");
                wordsArray.get(14).add("start");
            }
        }
    }

    /* This function will return inner array value
       assumes a correct inner and outter index is passed for now
     */
    public  String getVal(int outerIndex, int innerIndex){
        String value = wordsArray.get(outerIndex).get(innerIndex);
        return value;
    }

}
