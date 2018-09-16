//题目描述:
//有一天，小Q找到了一做矿山，我们可以把这座矿山抽象地看成一个字符串S。
//其中的每个矿石都可以看成一个字符，其中当一些矿石遵循一种特殊的元素排列时
//(用字符串P表示),它就构成一块能源石。
//同时，相邻的两块能源石能够合成一块更大的能源石，融合时它们前缀和后缀
//相同的部分可能会重叠在一起。
//比如:标准的能源石排列为aba,那么两块能源石的融合结果就肯呢个为{abaaba,ababa,aba}。
//一块能源石的能量等于它长度的平方。
//现在小Q希望你告诉他最多可以获得多少能量。

//输入描述:
//输入的第一行为字符串S,第二行为字符串P。|S|,|P|<=10^6
//输出描述:
//能够获得的能量总和

//示例1
//输入
//xyabababcba
//ab
//输出
//36

//示例2
//输入
//aaa
//aa
//输出
//9

//仅考虑了首末重复子串长度为1的情况
function test(str,sub){
    var result=0;
       if(sub[0]==sub[sub.length-1])
       {
        while(str.length>0)
        {
            var i1=str.indexOf(sub);

            var len1=0;
            var i2=-1;
            if(i1!==-1){
             len1+=sub.length;
             str=str.slice(i1+sub.length);
             i1=str.indexOf(sub);
             i2=str.indexOf(sub.slice(1));
            while(i1===0 || i2===0)
            {
                if(i1===0)
                {
                   len1+=sub.length;
                   str=str.slice(sub.length);
                }
                   else if(i2===0)
                  { 
                      len1+=sub.length-1;
                  str=str.slice(sub.length-1);
                  }
                  i1=str.indexOf(sub);
             i2=str.indexOf(sub.slice(1));
            }
            result+=len1*len1;
         }
         else{
             str="";
         }
        }
    }
       
       else{
           while(str.length>0)
           {
               var i3=str.indexOf(sub);

               var len=0;
               if(i3!==-1){
                len+=sub.length;
                str=str.slice(i3+sub.length);
                i3=str.indexOf(sub);
               while(i3===0)
               {
                      len+=sub.length;
                     str=str.slice(i3+sub.length);
                     i3=str.indexOf(sub);
               }
               result+=len*len;
            }
              else{
                  str="";
              }
           }
       }
       return result;
}

//需考虑首末重复子串长度不为1的情况
function test(str,sub){
    var result=0;
       if(sub[0]==sub[sub.length-1])
       {
        while(str.length>0)
        {
            var i1=str.indexOf(sub);
            
            var len1=0;
            var i2=-1;
            if(i1!==-1){
             len1+=sub.length;
             str=str.slice(i1+sub.length);
             i1=str.indexOf(sub);
             i2=str.indexOf(sub.slice(1));
            while(i1===0 || i2===0)
            {
                if(i1===0)
                {
                   len1+=sub.length;
                   str=str.slice(sub.length);
                }
                   else if(i2===0)
                  { 
                      len1+=sub.length-1;
                  str=str.slice(sub.length-1);
                  }
                  i1=str.indexOf(sub);
             i2=str.indexOf(sub.slice(1));
            }
            result+=len1*len1;
         }
         else{
             str="";
         }
        }
    }
       
       else{
           while(str.length>0)
           {
               var i3=str.indexOf(sub);

               var len=0;
               if(i3!==-1){
                len+=sub.length;
                str=str.slice(i3+sub.length);
                i3=str.indexOf(sub);
               while(i3===0)
               {
                      len+=sub.length;
                     str=str.slice(i3+sub.length);
                     i3=str.indexOf(sub);
               }
               result+=len*len;
            }
              else{
                  str="";
              }
           }
       }
       return result;
}
var a=test("xyabababcba","ab");//36
var b=test("aaa","aa");//9
console.log(a);
console.log(b);