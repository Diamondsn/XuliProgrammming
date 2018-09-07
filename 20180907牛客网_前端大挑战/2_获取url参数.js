// 题目描述
// 获取 url 中的参数
// 1. 指定参数名称，返回该参数的值 或者 空字符串
// 2. 不指定参数名称，返回全部的参数对象 或者 {}
// 3. 如果存在多个同名参数，则返回数组

// 示例1
// 输入
// http://www.nowcoder.com?key=1&key=2&key=3&test=4#hehe
// 输出
// [1, 2, 3]

function getUrlParam(sUrl, sKey) {
    var str=sUrl.split('#')[0].split('?')[1];
    var keyvaluearr=str===''?[]:str.split('&');
    var result={};
    for(var i=0;i<keyvaluearr.length;++i)
    {
        var key=keyvaluearr[i].split('=')[0];
        var value=keyvaluearr[i].split('=')[1];
        if(value)
        {
            if(result[key])
            {
                var temp=result[key];
                result[key]=[].concat(temp,value);
            }
            else
            {
                result[key]=value;
            }
        }
    }
    if(sKey===undefined)
    {return result;}
    else if(result[sKey])
    {return result[sKey];}
    else
    {return '';}
}

//test
console.log(getUrlParam('http://www.nowcoder.com?key=1&key=2&key=3&test=4#hehe'));
console.log(getUrlParam('http://www.nowcoder.com?key=1&key=2&key=3&test=4#hehe','key'));
console.log(getUrlParam('http://www.nowcoder.com?key=1&key=2&key=3&test=4#hehe','test'));