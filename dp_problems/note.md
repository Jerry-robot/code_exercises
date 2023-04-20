### 一、初始化数组为最大值
    1、memset:是按字节赋值，所以第二个参数最大为127
    `int arr[10];
    memset(arr, 127, sizeof(arr));`
    2、vector初始化按数据类型长度初始
    `vector<int> arr(10, 7fffffff);`



