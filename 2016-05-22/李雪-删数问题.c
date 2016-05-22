//给定一个n位正整数a，删掉其中任意k(k<=n)个位，剩下的为按原顺序形成一个新的正整数。
//找出剩下的数字最小的删树方案。
//输入：a>0，n位，0<k<=n。
//输出：最小的剩下的数。
//贪心策略：
//最近下降点优先。
//自左向右逐位扫描数字a，找到第i位，使得a[i]>a[i+1]，那么删掉第i位后，剩下的是当前数字删掉1位后的最小值。
//迭代k次，删掉k位即可。
/**
* 删数问题
* 给定一个n位正整数a，删掉其中任意k(k<=n)个位，剩下的为按原顺序形成一个新的正整数。
* 找出剩下的数字最小的删树方案。
* @author xuefeng
*/
public class RemoveNumBits {
    // ignore exceptions
    public static int RNB(int a, int k) {
        StringBuffer sb = new StringBuffer(a + "");
        int i, j;
        for (i = 0; i < k; i++) {
            for (j = 0; j < sb.length() - 1
                 && sb.charAt(j) <= sb.charAt(j + 1); j++) {
            }
            sb.delete(j, j + 1);
        }
        return sb.length() == 0 ? 0 : Integer.parseInt(sb.toString());
    }
    
    public static void main(String[] args) {
        int min = RNB(178543, 6);
        System.out.println(min);
    }
}  
