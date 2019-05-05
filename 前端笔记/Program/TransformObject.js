var obj = [
    {id: 1, parent: null},
    {id: 2, parent: 1},
    {id: 3, parent: 2}
];
function transform(obj, index){
    var node;
    if(index === obj.length-1){
        node = {
            id: obj[index].id,
            parent: obj[index].parent
        }
    }else {
        node = {
            id: obj[index].id,
            parent: obj[index].parent,
            next: transform(obj, index+1)
        }
    }
    return node;
}

let obj2 = {
    obj:transform(obj, 0)
};
console.log(obj2);
