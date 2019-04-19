var data=[{"id":"1","parentId":"0","name":"阿萨德发多少"},
{"id":"2","parentId":"1","name":"账户"},
{"id":"3","parentId":"1","name":"阿萨德发多少"},
{"id":"4","parentId":"2","name":"a啊都是发"},
{"id":"5","parentId":"4","name":"大夫"},
{"id":"6","parentId":"5","name":"通知公告"},
{"id":"7","parentId":"6","name":"；卡萨丁"},
{"id":"8","parentId":"7","name":"拉收到了"},
{"id":"9","parentId":"5","name":"网格化管理"},
{"id":"10","parentId":"9","name":"综合信息门户管理"}
];




var digui=function(data,parentId){
    var res=[];
    for(var i=0;i<data.length;++i){
        var node=data[i];
        if(node.parentId===parentId){
            var newNode={"id":node.id,"title":node.name,"nodes":digui(data,node.id)};
            res.push(newNode);
        }
    }
    return res;
}

var res=digui(data,"0");
console.log(res);












// var getJsonTree=function(data,parentId){
//         var itemArr=[];
//         for(var i=0;i<data.length;i++){ 
//             var node=data[i];
//             //data.splice(i, 1)
//              if(node.parentId==parentId ){ 
//                 var newNode={id:node.id,title:node.name,nodes:getJsonTree(data,node.id)};
//                 itemArr.push(newNode);              
//              }
//         }
//         return itemArr;
//     } 
// var jsonArray = getJsonTree(data,'0');
// console.log(jsonArray);