# mycenter
LiuDao 中心控制(天道)模块(开发中)
欢迎看我的中二项目  


主要依赖包：   
1. boost1.74  
2. mysql  
3. glog  

目前主要实现推理实例的注册，解除注册，上线，下线，MyCenter具有一定 的服务治理功能   
推理应用表
```
struct inferenceAPP
{
    string id;                                          //id 自增
    string inference_name;            //应用名字，暂时唯一
    string model_name;                  //模型名字
    string register_time;                  //注册时间
    string ip;                                          //ip+port
    int status;              //状态，1注册成功，2解除注册 数据库中移除，3上线，4下线
    string inference_input;             //模型输入支持image，text，e.g. {image:1;text:1}
    string inference_output;          //模型输出支持image，text，e.g. {image:1;text:1}
    int model_status;                         //模型状态，0：V-RAM，1：RAM，2：ROM
    double model_memery;           //模型占有RAM资源 
};
```

## 目前编译方式
```
mkdir build
cd build
cmake ..
make -j8
./hello_world_sever
```

TODO：  
center 线程逻辑
心跳探活  
