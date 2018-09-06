//n道题
//一道题可以选择不做，得0分，费时0分钟
//可以选择部分做，得arr[0][1]分，费时arr[0][2]分钟
//可以选择做完整道题，得arr[0][3]分，费时arr[0][3]分钟
//问最终能在120分钟内最高得多少分

//参数说明:n为题目道数，arr为二维数组，存储每道题所花费的
//两个时间和两个分数,time为所需时间，输入为120

//调用方法dongtaiguihua(n,arr,120)
function dongtaiguihua(n,arr,time)
{
    if(n<1)
        return 0;

        if(time<=0)
           return 0;
    
         var mygrade1=0
         var mygrade2=0;
         var mygrade3=0;
         mygrade1=dongtaiguihua(n-1,arr.slice(1),time);
         if(time>=arr[0][0])
             mygrade2=arr[0][1]+dongtaiguihua(n-1,arr.slice(1),time-arr[0][0]);
        
         if(time>=arr[0][2])
             mygrade3=arr[0][3]+dongtaiguihua(n-1,arr.slice(1),time-arr[0][2]);

         var maxgrade=mygrade1;
         if(maxgrade<mygrade2)
             maxgrade=mygrade2;

             if(maxgrade<mygrade3)
             maxgrade=mygrade3;
    

    return maxgrade;
}