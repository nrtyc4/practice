import java.util.Scanner;
import java.io.File;
import java.util.ArrayList;

public class Solution {
    public static ArrayList<Integer> read(File f) {
        ArrayList<Integer> array = new ArrayList<Integer>();
        try {
            Scanner sc = new Scanner(f);
            while (sc.hasNextLine()) {
                array.add(sc.nextLine());
            }
        } catch (Exception e) {
            System.out.printf("ERROR : %s", e);
        }
        return array;
    }
    
    public static void main(String[] args) {
        File file1 = new File("input.txt");
        ArrayList<Integer> array1;
        array1 = read(file1);
        System.out.println(array1);
    }
}
