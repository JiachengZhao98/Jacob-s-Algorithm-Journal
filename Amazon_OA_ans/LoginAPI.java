package com.robin.leetCode.design;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LoginAPI {

    List<String> logs = new ArrayList<String>();
    Map<String, String> user = new HashMap<String, String> ();
    Map<String, String> login = new HashMap<String, String> ();
    public void Register(String userName, String password){
        if(user.containsKey(userName)){
            logs.add("Username already exists");
        }else{
            logs.add("Registered Successfully");
        }
    }

    public void Login(String userName, String password){
        if(login.containsKey(userName)){
            //用户已经登陆. 不可以再登陆
            logs.add("Login Unsuccessful");
            return;
        }
        if(user.containsKey(userName)){
            if(user.get(userName).equals(password)){
                logs.add("Logged In Successfully");
                //登陆成功用户记录在login中.
                login.put(userName, userName);
            }else{
                //密码不匹配, 登陆失败
                logs.add("Login Unsuccessful");
            }
        }
    }

    public void Logout(String userName){
        if(login.containsKey(userName)){
            logs.add("Logged Out Unsuccessful");
            login.remove(userName);
        }else{
            logs.add("Logout Unsuccessful");
        }
    }
}
