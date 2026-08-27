import java.util.*;
class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int n = s.length();

        // Convert the string into a character list
        // so that we can remove individual characters.
        ArrayList<Character> chars = new ArrayList<>();

        for (char c : s.toCharArray()) {
            chars.add(c);
        }

        // Sort the characters.
        // This is important because later we need to find
        // the smallest character greater than target[i].
        Collections.sort(chars);

        /*
         * We try different positions from right to left.
         *
         * Example:
         * target = "abcd"
         *
         * First try:
         * prefix = "abc"
         *
         * If "abc" can be formed from s, we try to put
         * a character greater than 'd' after it.
         *
         * If that is not possible, we try:
         * prefix = "ab"
         *
         * and make the third character greater than target[2].
         */
        for (int i = n - 1; i >= 0; i--) {

            // Take the prefix of target before position i.
            String prefix = target.substring(0, i);

            /*
             * Make a copy of the sorted characters.
             *
             * We will remove characters from this copy
             * while trying to construct the prefix.
             */
            ArrayList<Character> temp = new ArrayList<>(chars);

            boolean possible = true;

            /*
             * Check whether the prefix can be formed
             * using the characters available in s.
             */
            for (char c : prefix.toCharArray()) {

                // Find this character in temp.
                int index = temp.indexOf(c);

                // Character does not exist.
                if (index == -1) {
                    possible = false;
                    break;
                }

                // Remove the character because it has
                // been used to construct the prefix.
                temp.remove(index);
            }

            // If prefix cannot be formed, try a shorter prefix.
            if (!possible) {
                continue;
            }

            /*
             * Now we need the smallest character
             * that is GREATER than target[i].
             *
             * Since temp is sorted, we can scan from left
             * to right and take the first character > target[i].
             */
            int greaterIndex = -1;

            for (int j = 0; j < temp.size(); j++) {

                if (temp.get(j) > target.charAt(i)) {
                    greaterIndex = j;
                    break;
                }
            }

            /*
             * If we found a character greater than target[i],
             * we can construct our answer.
             */
            if (greaterIndex != -1) {

                // Start with the target prefix.
                StringBuilder ans = new StringBuilder(prefix);

                // Add the smallest character greater than target[i].
                ans.append(temp.get(greaterIndex));

                // Remove that character because it is now used.
                temp.remove(greaterIndex);

                /*
                 * Add all remaining characters.
                 *
                 * temp is sorted, so adding them directly gives
                 * the smallest possible suffix.
                 */
                for (char c : temp) {
                    ans.append(c);
                }

                return ans.toString();
            }
        }

        // No permutation of s is lexicographically greater than target.
        return "";
    }
}
