package com.example.myapplication;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.TextView;

public class WordListActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_word_list);
        DataBase wordList= new DataBase(15);
        wordList.initialize();
        configBack();
        TextView num = (TextView) findViewById(R.id.textView2);
        String passedNum = getIntent().getExtras().getString("test");
        int outerIndex = Integer.parseInt(passedNum);
        String output = wordList.getVal(0, 0);
        num.setText(output);

    }
    private void configBack(){
        TextView back = (TextView) findViewById(R.id.textView2);
        back.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(WordListActivity.this, ListActivity.class);
                startActivity(intent);
            }
        });
    }
}
