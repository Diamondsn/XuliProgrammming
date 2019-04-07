// while(line=readline()){
//     var lines = line.split(" ");
//     var a = parseInt(lines[0]);
//     var b = parseInt(lines[1]);
//     print(a+b);
// }


function test(str1){
    var i,j,len1=str1.length;
    var t=0,k=0;
    for(i=0;i<len1;++i){
        var n1=Number(str1[i]);
        for(j=i+1;j<len1;++j){
            var n2=Number(str1[j]);
            if(n1==n2)
            k++;
            else
            continue;
        }
    }
    if(k%2==0)
    console.log("Oh,no.");
    else
    console.log("Yes,you can win!");
}

// var t=readline();
// var arr=[];
// for(var num=0;num<t;++num){
//     var s=readline();
//     arr.push(s);
// }
// for(num=0;num<arr.length;++num){
//     test(arr[num]);
// }

test("112233");