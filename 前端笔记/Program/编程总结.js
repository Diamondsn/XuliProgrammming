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
var head=new Node(1,node2);
shuchu(head);
console.log("更改方向");
shuchu(reverseList(head));
//1解 递归
// function reverseList(node) {
//     if(!node)
//     return node;
//     if(!node.next)
//     return node;
//     var curhead=reverseList(node.next);
//     var temphead=curhead;
//     while(temphead && temphead.next){
//         temphead=temphead.next;
//     }
//     temphead.next=node;
//     node.next=null;
//     return curhead;
// }
//2解 双指针
function reverseList(node) {
    if(!node ||!node.next)
     return node;
     var node1=null;
     var node2=node;
    while(node2){
        var temp=node2.next;
        node2.next=node1;
        node1=node2;
        node2=temp;
    }
    return node1;

}