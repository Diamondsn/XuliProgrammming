function output(str) {
    var doms=document.getElementByTagName("span");
    var shandong=document.getElementById("jsBlink");
    var content=docuemnt.getElementByTagName("div")[0];
    for(var i=0;i<doms.length;++i)
    {
        if(doms[i]!==shandong){
            doms[i].parentNode.removeChild(doms[i]);
        }
    }
    var pianduan=document.createDocumentFragment();
    for (i = 0; i < str.length; ++i) {
        var newdom = document.creatElement("span");
        if (str[i] === "\n") {
             var huanhang=document.createElement("br");
             newdom=huanhang;
        } else {
            if (str[i] === " ") {
                newdom.innerText = " ";
            } else if (str[i] === "<") {
                newdom.innerText="\<";
            }else if(str[i]==="\>"){
                newdom.innerText="\>";
            }
            newdom.className="word";
            newdom.className+=Math.random()%24;
        }
        pianduan.appendChild(newdom);
    }
    content.insertBefore(pian)
}

console.log(output("hello world"));