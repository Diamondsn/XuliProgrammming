var n=readInt();
var i=0;
var num;
var arr=[];
while(i<n){
    num=readInt();
     arr.push(num);
    i++;
}
function test(n,arr){
    var index=0;
    for(var j=n-1;j>=0;j--){
        var t=j-1;
        if(arr[j]<arr[t]){
            index=j;
            break;
        }
    }
    print(index);
}
test(n,arr);