class Node{
	int info;
	Node left,right;
	Node(int data){
		info = data;
		left=right=null;
	}
}

class specialTree{
	static Node special(int inOrder[],int start,int end){
		if(start>end){
			return null;
		}
		if(start==end){
			return (new Node(inOrder[start]));
		}
		int max = inOrder[start];
		int index=start;
		for(int i=start+1;i<=end;i++){
			if(inOrder[i]>max)
			{max = inOrder[i];
			index = i;
		}
		}
		
		Node temp = new Node(max);
		temp.left = special(inOrder,start,index-1);
		temp.right = special(inOrder,index+1,end);
		return temp;
	}

	public static void innOrder(Node root){
		if(root==null){
			return;
		}
		
		innOrder(root.left);
		System.out.print(" "+root.info);
		innOrder(root.right);
	}

	public static void main(String s[]){
		int inOrder[] = {1, 5, 10, 40, 30,15, 28, 20};
		Node root = special(inOrder,0,7);
		System.out.println("Printing newly made tree");
		innOrder(root);
		System.out.println();
	}	
}