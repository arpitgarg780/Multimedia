import java.util.*;

public class practical {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		
		ArrayList<Integer> out = encode(s);
		decode(out, s);
		sc.close();
		
	}
	
	public static ArrayList<Integer> encode(String s) {

		Hashtable<String, Integer> hm = new Hashtable<>();
		int cp=1;
		for(int i=0;i<s.length();i++) {
			if(hm.containsKey(s.charAt(i)+"")) {
				continue;
			}
			else {
				hm.put(""+s.charAt(i), cp++);
			}
		}
		
		ArrayList<Integer> out = new ArrayList<>();
		String p = ""+s.charAt(0), c="";
		int i=0, code = cp;
		float com=1;
		while(i<s.length()) {
			
			if(i!=s.length()-1) {
			c = ""+s.charAt(i+1);
			}
			
			if(hm.containsKey(p+c+"")) {
				p = p+c+"";
			}
			else {
				System.out.println(p +"\t" +hm.get(p)+"\t\t"+
						(p + c+"") +"\t" + code );
				com++;
				out.add(hm.get(p));
				hm.put(p+c, code);
				code++;
				p = c;
			}
			c="";
			i++;
			
		}
		
		System.out.println(p +"\t" +hm.get(p));
		out.add(hm.get(p));
		System.out.println(out);
		float cop =  s.length()/com;
		System.out.println("Compression ratio: "+ cop);
		return out;
	}
	
	public static void decode(ArrayList<Integer> out, String str) {
		
		Hashtable<Integer, String> hm = new Hashtable<>();
		
		int cp=1;
		for(int i=0;i<str.length();i++) {
			if(hm.containsKey(str.charAt(i)+"")) {
				continue;
			}
			else {
				hm.put(cp++,""+str.charAt(i));
			}
		}
			
				
		int old = out.get(0), n, i=0;
		String s = hm.get(old), c="";
		c += s.charAt(0);
		System.out.print(s);
		int count = cp;
				while(i<out.size()-1) {
					
					 n = out.get(i+1); 
					
					
					if(!hm.containsKey(n)) {
						s = hm.get(old);
						s = s+c;
					}
					else {
						s = hm.get(n);
					}
					System.out.print(s);
					c = "";
					c += s.charAt(0);
					hm.put(count, hm.get(old) + c);
					count++;
					old = n;
					i++;
				}
	}

}