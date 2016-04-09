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
		System.out.print(" "+root.value);
		Inorder(root.right);
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
        cloneRoot = c.doCloning(root);
        System.out.println("Printing cloned tree");
        c.Inorder(cloneRoot);
        System.out.println();
	}
}