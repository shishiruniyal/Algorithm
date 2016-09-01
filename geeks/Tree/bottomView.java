import java.util.*;
class Node{
	int data;
	Node left,right;
	int hd;
	Node(int value){
		data = value;
		left = right = null;
		hd = 0;
	}
}

class bottom{
	Map<Integer,Integer> m;
	void levelOrder(Node root){
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);

		while(!q.isEmpty()){
			Node temp = q.poll();
			m.put(temp.hd,temp.data);
			if(temp.left!=null){
				temp.left.hd = temp.hd-1;
				q.add(temp.left);
			}
			if(temp.right!=null){
				temp.right.hd = temp.hd+1;
				q.add(temp.right);
			}

		}
	}
	public static void main(String[] args) {
		bottom b = new bottom();

		b.m = new TreeMap<Integer,Integer>();

		Node root = new Node(20);

		root.left = new Node(8);
		root.right = new Node(22);

		root.left.left = new Node(5);
		root.left.right = new Node(3);

		root.right.right = new Node(25);
		//root.right.left = new Node(4);

		root.left.right.left = new Node(10);
		root.left.right.right = new Node(14);

		b.levelOrder(root);

		Set<Map.Entry<Integer,Integer>> set = b.m.entrySet();

		for(Map.Entry<Integer,Integer> i:set){
			System.out.print(i.getValue()+" ");
		}
	}
}