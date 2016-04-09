class Node{
	int value;
	Node left,right;

	Node(int v){
		left = null;
		right = null;
		value = v;
	}
}

class inAndPre{
	static int pe=0;
	public Node Build(int in[], int pre[],int si,int ei){
		
		if(si > ei){
			return null;
		}

		Node root = new Node(pre[pe++]);
		if(si==ei){
			return root;
		}

		int p  = findI(in,si,ei,root.value);
		root.left = Build(in,pre,si,p-1);
		root.right = Build(in,pre,p+1,ei);
		return root;
	}

	private	int findI(int in[],int si,int ei,int value){
		for(int i=si;i<=ei;i++){
			if(in[i]==value){
				return i;
			}
		}
		return -1;
	}


	public static void main(String s[]){
		int in[] = {4,2,5,1,3,6};
		int pre[] = {1,2,4,5,3,6};
		inAndPre ip = new inAndPre();
		Node root = ip.Build(in,pre,0,5);
		System.out.println("Inorder traversal of constructed tree is below:");
		ip.Inorder(root);
		System.out.println();
	}

	public void Inorder(Node root){
		if(root==null){
			return;
		}
		Inorder(root.left);
		System.out.print(" "+root.value);
		Inorder(root.right);
	}


}