typedef struct
{
    int dim,                    //数组维数
        *upper,                 //数组上界的指针
        *lower,                 //数组下界的指针
        *constants,            //数组映像函数常量基址
        *data,                  //数组元素内容
         num;                   //数组总个数    
        
}NArray;
