package com.orange.opencv;

import android.os.Bundle;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    String TAG = "MainActivity";

    static {
        System.loadLibrary("native-lib");
    }

    private static final String ROOT = Environment.getExternalStorageDirectory().getAbsolutePath();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView) findViewById(R.id.sample_text);
        long start = System.currentTimeMillis();
        loadJpeg(ROOT, ROOT + "/lena.jpg");
        Log.w(TAG, "SPEND :" + (System.currentTimeMillis() - start));
        tv.setText(stringFromJNI());
    }

    public native String stringFromJNI();

    public native void loadJpeg(String root, String path);
}
