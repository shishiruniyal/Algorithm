class Node{
	Node left,right;
	int value;

	Node(int data){
		value = data;
		left = null;
		right = null;
	}
}

class subtree{


	private Node find(Node root, Node root1){
		if(root==null){
			return null;
		}
		else {
			if(root.value == root1.value){
				return root;
			}
			Node answer1 = find(root.left,root1);
			Node answer2 = find(root.right,root1);
			if(answer1!=null){
				return answer1;
			}
			else if(answer2!=null){
				return answer2;
			}
			else{
				return null;
			}
	}
}

private boolean traversal(Node root1,Node temp){
	boolean answer;
	if(root1==null){
		return true;
	}
	else{
		if(temp!=null && root1.value==temp.value){
			answer = traversal(root1.left,temp.left);
			answer = answer & traversal(root1.right,temp.right);
			return answer;
		}
		else{
			return false;
		}
	}
}

public boolean test(Node root1,Node root2){
	Node temp = find(root2,root1);
	if(temp==null){
		return false;
	}
	return traversal(root1,temp);
}

public static void main(String s[]){
boolean answer;
Node root1 = new Node(10);
root1.left = new Node(4);
root1.right = new Node(6);
root1.right = new Node(6);
root1.left.right = new Node(30);


Node root2  = new Node(26);
root2.left  = new Node(10);
root2.right = new Node(3);
root2.right.right = new Node(3);
root2.left.right = new Node(6);
root2.left.left = new Node(4);


subtree sub = new subtree();
answer = sub.test(root1,root2);

if(answer){
	System.out.println("Yes it is a subtree");
}
else{
	System.out.println("Not a subtree");
}

}
}