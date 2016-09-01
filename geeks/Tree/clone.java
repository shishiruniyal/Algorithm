import java.util.HashMap;
class Node{
	int value;
	Node left,right,random;

	Node(int data){
		value = data;
		left = right = random = null;
	}
}


class clone{
	HashMap<Node,Node> hm ;
	public Node doCloning(Node root){
		Node newRoot;
		hm = new HashMap<Node,Node>();
		newRoot = new Node(root.value);
		hm.put(root,newRoot);
		modifiedInorder(root,newRoot);
		System.out.println("Clone Tree created");
		randomPointerCorrection(root,newRoot);
		return newRoot;

	}

	private void modifiedInorder(Node root,Node newRoot){
		if(root==null){
			return;
		}
		if(root.left!=null){
			newRoot.left = new Node(root.left.value);
			hm.put(root.left,newRoot.left);
		}
		if(root.right!=null){
			newRoot.right = new Node(root.right.value);
			hm.put(root.right,newRoot.right);
		}

		modifiedInorder(root.left,newRoot.left);
		modifiedInorder(root.right,newRoot.right);
	}

	private void randomPointerCorrection(Node root,Node newRoot){
		if(root==null){
			return;
		}
		newRoot.random = hm.get(root.random);
		randomPointerCorrection(root.left,newRoot.left);
		randomPointerCorrection(root.right,newRoot.right);
	}
	public void Inorder(Node root){
		if(root==null){
			return;
		}
		Inorder(root.left);
		
		if(root.random!=null)
			System.out.print(" "+root.value+" random = "+root.random.value);
		else
			System.out.print(" "+root.value);
		Inorder(root.right);
	}


//IF CHANGE OF TREE STRUCTURE IS ALLOWED

	void Modify2(Node root){
		if(root==null){
			return;
		}
		Node temp;
		temp = root.left;
		root.left = new Node(root.value);
		root.left.left = temp;
		Modify2(temp);
		Modify2(root.right);
	}
	void Modify2Random(Node root){
		if(root==null){
			return;
		}
		if(root.random!=null)
		root.left.random = root.random.left;
		Modify2Random(root.left.left);
		Modify2Random(root.right);
	}

	Node FinalCarving(Node root){
		if(root==null){
			return null;
		}
		Node newRoot = root.left;
		root.left = root.left.left;
		newRoot.left = FinalCarving(root.left);
		newRoot.right = FinalCarving(root.right);
		return newRoot;
	}

	public static void main(String s[]){
		Node cloneRoot;
		Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
       	root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.random = root.left.right;
        root.left.right.random = root;
        clone c = new clone();
        System.out.println("Normal tree");
        c.Inorder(root);
        System.out.println();
        // cloneRoot = c.doCloning(root);
        // System.out.println("Printing cloned tree");
        // c.Inorder(cloneRoot);
        // System.out.println();

 		
 		// New appraoch with changing out tree

        c.Modify2(root);
   
   

        c.Modify2Random(root);
 
        System.out.println("Finally carved out tree is");

       	Node newNode = c.FinalCarving(root);

        c.Inorder(newNode);

        System.out.println();
        System.out.println("Original tree");

        c.Inorder(root);

        System.out.println();


	}
}