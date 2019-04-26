//1.实现反转函数
class Node {
    constructor(value, next) {
        this.value = value;
        this.next = next;
    }
}
function shuchu(node){
    while(node){
        console.log(node.value);
        node=node.next;
    }
}
var node3=new Node(3,null);
var node2=new Node(2,node3);
var head=new Node(1,node1);
shuchu(head);
console.log("更改方向");
shuchu(reverseList(head));
//1解 递归
function reverseList(node) {
    if(!node)
    return node;
    if(!node.next)
    return node;
    var curhead=reverseList(node.next);
    var temphead=curhead;
    while(temphead && temphead.next){
        temphead=temphead.next;
    }
    temphead.next=node;
    return curhead;
}