import java.util.Stack;

class Node{
	Node left,right;
	int value;

	Node(int item){
		left = null;
		right = null;
		value = item;
	}
}


class Main{

	void Inorder(Node root){
		Stack<Node> n = new Stack<Node>();
		n.push(root);
		Node current = root;

		while(!n.isEmpty()){
			while(current!=null){
				current = current.left;
				if(current!=null)
				n.push(current);
			}

			current = n.pop();
			System.out.print(current.value+" ");

			if(current.right!=null){
				current = current.right;
				n.push(current);
			}
		}
	}

	public static void main(String s[]){

		Main m = new Main();
		Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        m.Inorder(root);
	}
}