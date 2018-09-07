// 题目描述
// 将 rgb 颜色字符串转换为十六进制的形式，如 rgb(255, 255, 255) 转为 #ffffff
// 1. rgb 中每个 , 后面的空格数量不固定
// 2. 十六进制表达式使用六位小写字母
// 3. 如果输入不符合 rgb 格式，返回原始输入

// 示例1
// 输入
// 'rgb(255, 255, 255)'

// 输出
// #ffffff

function rgb2hex(sRGB) {
    //判断是否符合rgb格式
    var reg=/rgb\((\d+),\s*(\d+),\s*(\d+)\)/;
    var res=sRGB.match(reg);
    //console.log(res);
    if(!res)
        return sRGB;
    else
    {
          var result='#';
          for(var i=1;i<4;++i)
          {
              var number=parseInt(res[i]);
              if(number>=0 && number<=255)
              {
                result+=number<16?'0'+number.toString(16):number.toString(16);
              }
              else
              {
                  return sRGB;
              }
          }
          return result;
    }
}

//test
console.log(rgb2hex('rgb(256,    255,   255)'));