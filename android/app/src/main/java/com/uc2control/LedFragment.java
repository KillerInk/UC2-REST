package com.uc2control;

import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.api.RestClient;

import java.util.Arrays;

/**
 * A simple {@link Fragment} subclass.
 * Use the {@link LedFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class LedFragment extends Fragment {

    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    public LedFragment() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment LedFragment.
     */
    // TODO: Rename and change types and number of parameters
    public static LedFragment newInstance(String param1, String param2) {
        LedFragment fragment = new LedFragment();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            mParam1 = getArguments().getString(ARG_PARAM1);
            mParam2 = getArguments().getString(ARG_PARAM2);
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        return inflater.inflate(R.layout.fragment_led, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        Button requestFeaturesButton = view.findViewById(R.id.button_getFeatures);
        EditText url = view.findViewById(R.id.editTextUrl);
        TextView features = view.findViewById(R.id.textView_features);
        requestFeaturesButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                features.setText("");
                RestClient restClient = new RestClient("http://" +url.getText().toString());


                    new Thread(new Runnable() {
                        @Override
                        public void run() {
                            try {
                                String[] fetures;
                                fetures = restClient.getFeatures();
                                features.post(new Runnable() {
                                    @Override
                                    public void run() {
                                        features.setText(Arrays.toString(fetures));
                                    }
                            });
                            } catch (Exception e) {
                                features.post(new Runnable() {
                                    @Override
                                    public void run() {
                                        features.setText(e.getMessage());
                                    }
                                });
                            }
                        }
                    }).start();




            }
        });
    }
}