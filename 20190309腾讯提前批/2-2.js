function com(n1,n2){
    return(n1<n2)?-1:1;
}

function res(arr1,arr2,arr3){
    var arr5=[],
    n=arr1[0],
    m=arr1[1];
    var k=1;
    for(i=0;i<m;i++){
        var t1=arr3[i],arr4=[];
        for(var j=0;j<t1;j++){
            arr4.push(arr2[j]);
        }
        arr4.sort(com);
        arr5.push(arr4[k-1]);
        k++;
    }
    return arr5;
}



//第一行
var line1=readline().split(" ");
var line2=readline().split(" ");
var line3=readline().split(" ");
var resarr=res(line1,line2,line3);
for(var i=0;i<resarr.length;++i){
    print(resarr[i]);
}