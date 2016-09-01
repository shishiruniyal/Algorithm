import java.util.*;
class Node{
	int data;
	Node left,right;

	Node(int value){
		data = value;
		left = right = null;

	}
}

class TreeF{

	static int preStart = 0;

	Node MakeTree(int pre[],int pos[],int startPos,int endPos){
		if(preStart==pre.length){
			return null;
		}
		Node temp = new Node(pre[preStart]);
		preStart++;
		if(startPos==endPos){
			return temp;
		}
		if(preStart<pre.length){
		int j = FindinPos(pre[preStart],startPos,endPos,pos);
		temp.left = MakeTree(pre,pos,0,j);
		temp.right = MakeTree(pre,pos,j+1,endPos-1);
		return temp;
		}
		if(preStart==pre.length){
			return temp;
		}
		else{
			return null;
		}
	} 

	int FindinPos(int item,int startPos,int endPos,int pos[]){
		while(startPos<=endPos){
			if(pos[startPos]==item){
				return startPos;
			}
			startPos++;
		}
		return -1;
	 }
	void preOrderTraver(Node root){
		if(root==null){
			return;
		}
		System.out.print(root.data+" ");
		preOrderTraver(root.left);
		preOrderTraver(root.right);
	}
	public static void main(String[] args) {
		
		int pre[]={1,2,4,8,9,5,3,6,7};
		int pos[]={8,9,4,5,2,6,7,3,1};
		TreeF f= new TreeF();
		System.out.println();
		f.preOrderTraver(f.MakeTree(pre,pos,0,8));
		System.out.println();
	}
}