# mycenter
MyImageTool 中心控制模块   
开发工具vscode  
目前是一个http 服务器，基于simple-web-server框架+mysql开发  


目前主要实现推理实例的注册，解除注册，上线，下线，MyCenter具有一定 的服务治理功能 
推理应用
```
struct inferenceAPP
{
    string id;                                          //id 自增
    string inference_name;            //应用名字，暂时唯一
    string model_name;                  //模型名字
    string register_time;                  //注册时间
    string ip;                                          //ip+port
    int status;                                        //状态，0注册成功，1解除注册数据库中移除，2上线，3下线
    string inference_input;             //模型输入支持image，text，e.g. {image:1;text:1}
    string inference_output;          //模型输出支持image，text，e.g. {image:1;text:1}
    int model_status;                         //模型状态，0：V-RAM，1：RAM，2：ROM
    double model_memery;           //模型占有RAM资源 
};
```

