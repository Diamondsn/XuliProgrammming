// 题目描述
// 根据包名，在指定空间中创建对象

// 输入描述:
// namespace({a: {test: 1, b: 2}}, 'a.b.c.d')
// 输出描述:
// {a: {test: 1, b: {c: {d: {}}}}}

function namespace(oNamespace, sPackage) {
    //20180906 9:51
    //此处eval用法需注意，同时若路径名本身取得是对象，则无需操作，只在不是对象时
    //将属性值修改为空对象
    var arr=sPackage.split('.');
    var path='oNamespace';
    if(arr)
    {
        for(var i=0;i<arr.length;++i)
        {
            path+='["'+arr[i]+'"]';
            if(typeof eval(path)!=='object')
            {
                eval(path+'={}');
            }
        }
    }
    return oNamespace;
}

//test
console.log(namespace({a: {test: 1, b: 2}}, 'a.b.c.d'));