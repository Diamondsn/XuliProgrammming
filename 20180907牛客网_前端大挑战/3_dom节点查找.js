// 题目描述
// 查找两个节点的最近的一个共同父节点，可以包括节点自身

// 输入描述:
// oNode1 和 oNode2 在同一文档中，且不会为相同的节点

function commonParentNode(oNode1, oNode2) {
    //20180905 22:19将两条顺位线存入容器，再找出第一个公共元素
    var arr1=[];
    var arr2=[];
    while(oNode1)
    {
         arr1.push(oNode1);
        oNode1=oNode1.parentNode;
    }
    while(oNode2)
    {
        arr2.push(oNode2);
        oNode2=oNode2.parentNode;
    }
    for(var i=0;i<arr1.length;++i)
    {
        if(arr2.indexOf(arr1[i])>=0)
            return arr1[i];
    }
    return null;
    
    //使用其他api或迭代求解
}