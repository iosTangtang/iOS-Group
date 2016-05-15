//希尔排序可以说是将插入排序分组，大概思路是：将数组元素按照相隔“增量”个元素分为若干组（如增量为3时，a0，a3为一组，a1，a4为一组，a2，a5为一组），然后对若干组分别作直接插入排序，排序后再缩小增量，直到增量为1时排序后结束。
void shell（int *a,int len）
{
    int j,k,t,gap;
    for(gap=n/2;gap>0;gap/=2;)
    {
        for(j=gap;j<n;j++)
        {
            if(a[j]<a[j-gap])
            {
                t=a[j];
                k=j-gap;
                while(k>=0&&a[k]>t)
                {
                    a[k+gap]=a[k];
                    k-=gap;
                }
                a[k+gap]=t;
            }
        }
    }
}
//对于增量的选择，一般情况是选len/2作为第一次，然后依次/2，直到为1。