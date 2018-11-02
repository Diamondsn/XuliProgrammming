#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//给出两个图像 A 和 B ，A 和 B 为大小相同的二维正方形矩阵。（并且为二进制矩阵，只包含0和1）。
//我们转换其中一个图像，向左，右，上，或下滑动任何数量的单位，并把它放在另一个图像的上面。之后，该转换的重叠是指两个图像都具有 1 的位置的数目。
//（请注意，转换不包括向任何方向旋转。）
//最大可能的重叠是什么？
//
//示例 1:
//输入：A = [[1,1,0],
//          [0,1,0],
//          [0,1,0]]
//     B = [[0,0,0],
//          [0,1,1],
//          [0,0,1]]
//输出：3
//解释: 将 A 向右移动一个单位，然后向下移动一个单位。
//
//注意: 
//1 <= A.length = A[0].length = B.length = B[0].length <= 30
//0 <= A[i][j], B[i][j] <= 1

//int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
//	vector<vector<int>>C(A.size()*3-2,vector<int>(A.size()*3-2,0));
//	for (int i = 0; i < A.size(); ++i){
//		for (int j = 0; j < A.size(); ++j){
//			C[A.size() - 1 + i][A.size() - 1 + j] = A[i][j];
//		}
//	}
//	int max = 0,cur=0;
//	for (int i = 0; i < 2 * A.size() - 1; ++i){
//		for (int j = 0; j < 2 * A.size() - 1; ++j){
//			cur = 0;
//			for (int m = 0; m < A.size(); ++m){
//				for (int n = 0; n < A.size(); ++n){
//					cur += C[i + m][j + n] & B[m][n];
//				}
//			}
//			if (cur > max)
//				max = cur;
//		}
//	}
//	return max;
//}

//以下解法来自Leetcode，只用2*n+1的空间
int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
	int len = A.size();
	vector<vector<int>>m_map(2 * len , vector<int>(2 * len, 0));
	for (int i_A = 0; i_A<len; ++i_A)
		for (int j_A = 0; j_A<len; ++j_A)
			if (A[i_A][j_A] == 1)
				for (int i_B = 0; i_B<len; ++i_B)
					for (int j_B = 0; j_B<len; ++j_B)
						if (B[i_B][j_B] == 1)++m_map[i_A - i_B + len][j_A - j_B + len];
	int ret = 0;
	for (int i = 0; i<m_map.size(); ++i)
		for (int j = 0; j<m_map[i].size(); ++j)
			ret = max(ret, m_map[i][j]);
	return ret;
}
int main() {
	//test1
	vector<vector<int>>A = { { 1, 1, 0 }, { 0, 1, 0 }, { 0, 1, 0 } },
		B = {{ 0, 0, 0 }, {0,1,1}, {0,0,1}};
	int a = largestOverlap(A, B);
	cout << a << endl;
	//test end
	system("pause");
	return 0;
}