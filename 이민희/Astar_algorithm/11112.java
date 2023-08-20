import java.util.*;
import java.io.*;
public class Main {
	static int T;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	static char[][] board;
	static int[] dr = {-1,0,1,0};
	static int[] dc = {0,1,0,-1};
	static HashMap<Integer,Integer> visitMap = new HashMap<>(); //이미 봤던 모양은 또 보지않기위해 key값으로 방문 여부 체크 
	static HashSet<Integer> impossibleSet =  new HashSet<Integer>(); //memoization
	static PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>() {
		@Override
		public int compare(Node o1, Node o2){
			if(o1.f==o2.f) return Integer.compare(o1.g,o2.g); //f = g+h라면 좀 더 이동회수가 적었던 노드가 더 우선순위를 가짐.
			return Integer.compare(o1.f,o2.f); //f = g+h에서 f기준으로 정렬 
		}
	});
	static class Node{
		String board;
		int g; //g(x)
		int f; //f(x)
		public Node(String data,int g,int f) {
			this.board = data;
			this.g=g;
			this.f=f;
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		T = Integer.parseInt(br.readLine()); // 첫번째 줄 숫자 받기. 몇 번의 퍼즐을 받을지
		for(int testcase=1;testcase<=T;testcase++) {
			br.readLine();//빈라인 read처리
			setData(); // board를 읽고, pq와 visitedMap에 넣어줌.
			astarAlgorithm(); //AstarAlgorithm
			if(visitMap.containsKey(Integer.parseInt("123456789"))) {
				bw.write((int) visitMap.get(Integer.parseInt("123456789"))+"\n");
				
			}else {//불가능하다는 판단이 나온 경우, 지나온 과정 모든 것이 불가능한 결과로 가는 과정이므로 Memoization 
				for(Integer key : visitMap.keySet()) impossibleSet.add(key);
				bw.write("impossible"+"\n");
			}
		}
		bw.flush();
		bw.close();
	}
	private static void astarAlgorithm(){
		while(!pq.isEmpty()) {
			Node currentNode = pq.poll(); // poll() : priority Queue가 비어있으면 null 반환
			String numberBoard = currentNode.board;
			int sharpIndex = numberBoard.indexOf("9"); //빈공간의 위치 인덱스
			int cr = sharpIndex / 3;
			int cc = sharpIndex % 3; // cr, cc는 row, column의 위치이다.
			
			//불가능한 케이스로 메모가 되어있는 경우 더이상 진행하지 않고 즉시 끝낸다.
			if(impossibleSet.contains(Integer.parseInt(numberBoard))) return;
			
			String data = "";
			for(int dir = 0; dir < 4; dir++) {//move UP,RIGHT,LEFT,DOWN
				int nr = cr + dr[dir];
				int nc = cc + dc[dir];
				if (rangeCheck(nr,nc)) { //영역을 만족 하는 경우
					StringBuilder next = new StringBuilder(numberBoard);
					next = swap(cr,cc,nr,nc,next); //swap
					data = next.toString();
					
					if(visitMap.containsKey(Integer.parseInt(data))) continue; //이미 본 케이스면 건너뛴다.
					else {
						/*
						 * heuristic logic
						 *f = g+h (현재 depth + 휴리스틱 값)
						 */
						int g = currentNode.g; // 현재 노드의 g
						int heuristic = getHeuristicValue(data); //h(x) 휴리스틱 function
						int f = g + heuristic;
						pq.add(new Node(data, g + 1, f));
						visitMap.put(Integer.parseInt(data), g + 1);
					}
				}
			}
			//조사 후 
			if(visitMap.containsKey(Integer.parseInt("123456789"))) return; //찾았으면 끝냄 
			
		}
	}
	private static int getHeuristicValue(String data){
		//이미 목표 위치에 있는 숫자가 많을수록 더 가치있다고 판단하였다.   
		//Manhattan Distance나 다른 어떤 가치 판단 로직을 세워 더 효율적인 휴리스틱 펑션을 만들어도 된다.
		int count = 0;
		for(int i = 0; i < data.length(); i++) {
			if ("123456789".charAt(i) != data.charAt(i)) count++;//같은 위치에 같은 숫자면 conut++
		}
		return count;
	}
	private static StringBuilder swap(int cr, int cc, int nr, int nc, StringBuilder next) {
		int currentRC = cr*3+cc;
		int nextRC = nr*3+nc;
		char temp = next.charAt(currentRC);
		next.setCharAt(currentRC,next.charAt(nextRC));
		next.setCharAt(nextRC,temp);
		return next;
	}
	private static boolean rangeCheck(int nr, int nc){
		if(nr>=0 && nr<3 && nc>=0 && nc<3) return true;
		return false;
	}
	private static void setData() throws IOException { // board를 세팅한다.
		board = new char[3][3];
		visitMap.clear(); //새로운 케이스에 대한 초기화
		pq.clear();
		String boardStr="";
		for(int row=0;row<3;row++) {
			board[row] = br.readLine().toCharArray();
			for(int col=0;col<3;col++) {
				if(board[row][col]=='#') board[row][col] = '9'; //빈공간을 숫자 9로 치환한다. Integer.parseInt를 쓰기위함
				boardStr+=board[row][col];
			}
		}
		pq.add(new Node(boardStr,0,0));
		visitMap.put(Integer.parseInt(boardStr),0);
	}
}
// [출처] [백준-11112] Eight Puzzle (Astar Algorithm)|작성자 지젝

