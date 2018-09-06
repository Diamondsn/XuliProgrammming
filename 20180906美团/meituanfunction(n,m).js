//n个懂算法的，n个懂知识的，每队3个人，必须含有一个懂算法和懂知识的，问最多组多少队

function(n,m)
{
    if(n==0 || m==0)
      return 0;

    suanfa=n;
    other=m;
    count=0;
    while(suanfa>0 && other>0 && suanfa+other>=3)
    {
        suanfa--;
        other--;
        if(suanfa>=other)
        suanfa--;
        else
        {
            other--;
        }

        count++;
    }

return count;
}