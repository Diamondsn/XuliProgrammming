// 题目描述
// 判断输入是否是正确的邮箱格式

// 输入描述:
// 邮箱字符串
// 输出描述:
// true表示格式正确

function isAvailableEmail(sEmail)
{
    //var reg=/^\w+((-\w)|(\.\w))*@[a-zA-Z0-9]+((-|\.)[a-zA-Z0-9])*\.[a-zA-Z0-9]+$/g;
    var reg=/^(\w)+(\.\w+)*@\w+(\.\w+)+$/;
    var result=reg.test(sEmail);
    return result;
}

//test
console.log(isAvailableEmail('1756625653@qq.com')==true);
console.log(isAvailableEmail('1756625653')==false);
console.log(isAvailableEmail('1756625653@qqq')==false);
console.log(isAvailableEmail('')==false);
console.log(isAvailableEmail('1756625653@qq.')==false);
console.log(isAvailableEmail('1756625653@qq.-')==false);
console.log(isAvailableEmail('@1756625653@qq.com')==false);