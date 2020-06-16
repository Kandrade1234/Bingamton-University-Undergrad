package com.example.myapplication;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageView;

public class ListActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        configureList1();
        configureList2();
        configureList3();
        configureList4();
        configureList5();
        configureList6();
        configureList7();
        configureList8();
        configureList9();
        configureList10();
        configureList11();
        configureList12();
        configureList13();
        configureList14();
        configureList15();
    }

    private void configureList1(){
        ImageView button = (ImageView) findViewById(R.id.imageView5);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                String s = "1";
                intent.putExtra("test", s);
                startActivity(intent);
            }
        });
    }

    private void configureList2(){
        ImageView button = (ImageView) findViewById(R.id.imageView6);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "2");
                startActivity(intent);
            }
        });
    }

    private void configureList3(){
        ImageView button = (ImageView) findViewById(R.id.imageView7);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "3");
                startActivity(intent);
            }
        });
    }

    private void configureList4(){
        ImageView button = (ImageView) findViewById(R.id.imageView8);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "4");
                startActivity(intent);
            }
        });
    }

    private void configureList5(){
        ImageView button = (ImageView) findViewById(R.id.imageView9);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "5");
                startActivity(intent);
            }
        });
    }

    private void configureList6(){
        ImageView button = (ImageView) findViewById(R.id.imageView10);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "6");
                startActivity(intent);
            }
        });
    }

    private void configureList7(){
        ImageView button = (ImageView) findViewById(R.id.imageView11);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "7");
                startActivity(intent);
            }
        });
    }

    private void configureList8(){
        ImageView button = (ImageView) findViewById(R.id.imageView12);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "8");
                startActivity(intent);
            }
        });
    }

    private void configureList9(){
        ImageView button = (ImageView) findViewById(R.id.imageView13);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "9");
                startActivity(intent);
            }
        });
    }

    private void configureList10(){
        ImageView button = (ImageView) findViewById(R.id.imageView14);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "10");
                startActivity(intent);
            }
        });
    }

    private void configureList11(){
        ImageView button = (ImageView) findViewById(R.id.imageView15);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "11");
                startActivity(intent);
            }
        });
    }

    private void configureList12(){
        ImageView button = (ImageView) findViewById(R.id.imageView16);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "12");
                startActivity(intent);
            }
        });
    }

    private void configureList13(){
        ImageView button = (ImageView) findViewById(R.id.imageView17);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "13");
                startActivity(intent);
            }
        });
    }

    private void configureList14(){
        ImageView button = (ImageView) findViewById(R.id.imageView18);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "14");
                startActivity(intent);
            }
        });
    }

    private void configureList15(){
        ImageView button = (ImageView) findViewById(R.id.imageView19);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ListActivity.this, WordListActivity.class);
                intent.putExtra("test", "15");
                startActivity(intent);
            }
        });
    }
}