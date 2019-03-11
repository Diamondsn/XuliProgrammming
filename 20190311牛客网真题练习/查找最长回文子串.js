// 给定一个字符串（数字或大小写字母）, 找出最长的对称的子串（如有多个，输出任意一个）。
// 例如：
// 输入：“abbaad”
// 输出：“abba”'

var str="abbaad";

//法1:暴力轮询，O(n^2)
function reverseStr(str){
    return str.split("").reverse().join("");
}
function test1(str){
     if(str.length<=1||reverseStr(str)===str)
          return str;
     var maxLength=0;
     var result;
     for(var i=1;i<str.length;++i){
         for(var j=0;j<i;++j){
             var curStr=str.slice(j,i+1);
             if(curStr.length>maxLength && curStr===reverseStr(curStr)){
                result=curStr;
                maxLength=curStr.length;
             }
         }
     }
     return result;
}


//法2:动态规划
function test2(str){
    var dp=[];
    for(var i=0;i<str.length;++i){
        var arr=new Array(str.length).fill(0);
        dp.push(arr);
    }
    var maxLength=0;
    var start=0;
    for(var i=0;i<str.length;++i){
        dp[i][i]=1;
        if(1>maxLength){
            maxLength=1;
            start=i;
        }
        if(i+1<str.length && str[i]===str[i+1]){
            dp[i][i+1]=1;
            if(2>maxLength){
                maxLEngth=2;
                start=i;
            }
        }
    }
    
for(var len=3;len<=str.length;++len){
    for(var i=0;i<str.length-len+1;++i){
         var j=i+len-1;
         if(str[i]===str[j]&& dp[i+1][j-1]==1){
             dp[i][j]=1;
             start=i;
             maxLength=len;
         }
    }
}
return str.slice(start,start+maxLength);
}



console.log(test1(str));
console.log(test2(str));