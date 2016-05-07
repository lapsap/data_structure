#include<iostream>
#include<vector>

using namespace std;

struct node{
	int value,l,r;
	node *left,*right;
	node(){
		value=0; l=0; r=0;
		left = NULL; right = NULL;
	}
};
struct bt{
	node *root;
	bt(){}
	bt(vector<int> &vec){
		root = insert(vec,1,0,vec.size()-1);
	}
	node *insert(vector<int> &vec,int pos,int left, int right){
		node *tmp = new node();	
		int length = (left+right)/2;
		if( left == right) {
			tmp->value = vec[left];
		}else {
			tmp->left = insert( vec, pos*2 , left, length );
			tmp->right = insert( vec, (pos*2)+1 , length+1, right);
			tmp->value = tmp->left->value + tmp->right->value;
		}
		tmp->l = left; tmp->r = right;
		return tmp;
	}
	
	void travel(){
		tra(root);
		cout << endl;
	}
	void tra(node *tmp){
		cout << tmp->value << " " << tmp->l << " " << tmp->r << endl;
		if(tmp->left != NULL) tra(tmp->left);
		if(tmp->right != NULL) tra(tmp->right);
	}
	
	int query(int left, int right){
		node *tmp = root;
		return quer(tmp,left,right);
	}
	int quer(node *tmp,int left, int right){
		if( tmp->l>=left && tmp->r<=right ){
			return tmp->value;
		}
		else if( left < tmp->l && right > tmp->r ){
			return 0;
		}	
		else{
			int mid = (left + right) /2;
			int p1=0,p2=0;
			if(tmp->left!=NULL)  p1 = quer(tmp->left, left, right);
			if(tmp->right!=NULL) p2 = quer(tmp->right, left, right);
			return p1+p2;
		}

		return -1;
	}
};

int main(){
vector<int> vec;
//for(int i=1;i<8;i++) vec.push_back(i);
vec.push_back(-5);vec.push_back(5);vec.push_back(5);vec.push_back(-15);
vec.push_back(7);
	bt tree(vec);
	cout << tree.query(0,4) << endl;
}
