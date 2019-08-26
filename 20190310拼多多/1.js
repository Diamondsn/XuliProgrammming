var str="333AABBCAZDFEH"
function quchong4(str){
	var obj={};
	var newStr="";
	for(var i=0;i<str.length;i++){
		if(!obj[str[i]]){
			newStr+=str[i];
			obj[str[i]]=1;
		}
	}
	return newStr;
}
console.log(quchong4(str))