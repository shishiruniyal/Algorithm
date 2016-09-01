import java.util.*;
class Node{
	int data;
	Node left;
	Node right;

	Node(int value){
		data = value;
		left = right = null;
	}
}

class Kth{

	void Print(Node root,int k,Set<Integer> s){
		PritUtil(root,k,"",s);
	}

	void PritUtil(Node root,int k,String path,Set<Integer> s){
		if(root==null){
			return;
		}
		path = path+root.data;
		if(root.left==null&&root.right==null){
			if(path.length()>k){
					s.add(path.charAt(path.length()-k-1)-'0');
				}
			
		}

		PritUtil(root.left,k,path,s);
		PritUtil(root.right,k,path,s);
	}


	void Downwards(Node target,int level,int k){
		//System.out.println("Downwards "+k);
		if(target==null){
			return;
		}
		if(level==k){
			System.out.print(target.data+" ");
		}
		Downwards(target.left,level+1,k);
		Downwards(target.right,level+1,k);
	}

	int search(Node root,Node target,int k){
		if(root==null||target==null){
			return -1;
		}
		if(target.data==root.data){
			Downwards(root,0,k);
			return 1;
		}
		int left = search(root.left,target,k);
		//System.out.println("Left = "+left);
		if(left!=-1){
			if( k-left>0){
			Downwards(root.right,0,k-left-1);
			return left+1;
		}
		else if (k-left==0){
			System.out.println(root.data+" ");
			return left+1;
		}
		}
		else{
			int right = search(root.right,target,k);
			//System.out.println("right = "+right);
		if(right!=-1&&k-right>0){
			if(k-right>0){
			Downwards(root.left,0,k-right-1);
			return right+1;
		}
		else if(k-right==0){
				System.out.println(root.data+" ");
				return right+1;
		}
		}
		}
		return -1;
	}
	public static void main(String[] args) {
		Node root = new Node(20);
		Node target;
		root.left = new Node(8);
		root.right = new Node(22);

		root.left.left = new Node(4);
		root.left.right = new Node(12);

		root.left.right.left = new Node(10);
		target = root.left.right.right = new Node(14);

		
		Kth k = new Kth();
		// Set<Integer> s = new HashSet<Integer>();
		// k.Print(root,0,s);
		// for(int i:s){
		// 	System.out.print(i+" ");
		// }
		int kk = 3;
		int an = k.search(root,target,kk);
		System.out.println();

	}
}