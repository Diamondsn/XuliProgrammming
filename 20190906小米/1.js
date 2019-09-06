// 题目描述：
// 在某个存储介质以如下形式保存一棵二叉树
// 1(2(3,4(,5)),6(7,))
// 上述序列表示的二叉树如下

// 观察后可以发现，每个节点的格式为
// X，X可以为空
// 或者
// X(Y, Z)，其中X不为空

// 请编写程序将以上述格式输入的二叉树输出为中序遍历顺序
// 输入
// 上述格式表示的二叉树字符串，用字符1~9表示每个二叉树的每个节点，字符可以重复使用
// 输出
// 二叉树的中序遍历结果

// 样例输入
// 1(2(3,4(,5)),6(7,))
// 样例输出
// 3245176

function solution(input) {
    function Node(val, left, right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
    function goujian(input) {
        if (input == "") {
            return null;
        }

        let kuohao = input.indexOf("(");
        let node = null;
        if (kuohao == -1) {
            node = new Node(parseInt(input), null, null);
        } else {
            let str = input.slice(kuohao + 1, -1);
            let leftstr = "", rightstr = "";
            //有左括号，需要轮训
            if (str.indexOf("(") == -1) {
                let index = str.indexOf(",");
                leftstr = str.slice(0, index);
                rightstr = str.slice(index + 1);
            } else {
                let count = 0, newindex = 0;
                for (let i = 0; i < str.length; ++i) {
                    if (str[i] == "(") {
                        count++;
                    } else if (str[i] == ")") {
                        count--;
                    } else if (str[i] == ",") {
                        if (count == 0) {
                            newindex = i;
                            break;
                        }
                    }
                }
                leftstr = str.slice(0, newindex);
                rightstr = str.slice(newindex + 1);
            }

            let myleft = goujian(leftstr);
            let myright = goujian(rightstr);
            node = new Node(parseInt(input.slice(0, kuohao)), myleft, myright);
        }
        return node;
    }

    let zhongxures = [];

    function zhongxubianli(head) {
        if (!head) return;

        zhongxubianli(head.left);
        zhongxures.push(head.val);
        zhongxubianli(head.right);
    }

    let head = goujian(input);
    zhongxubianli(head);
    return zhongxures.join("");
}

console.log(solution("1(2(3,4(,5)),6(7,))"));