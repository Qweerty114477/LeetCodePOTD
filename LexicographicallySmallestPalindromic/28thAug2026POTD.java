class Solution {

    public String lexPalindromicPermutation(String s, String target) {

        int n = s.length();

        // Frequency of each character
        int[] freq = new int[26];

        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        // Find middle character (if any)
        String middle = "";

        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2 == 1) {

                // More than one odd frequency => no palindrome possible
                if (!middle.isEmpty()) {
                    return "";
                }

                middle = String.valueOf((char) ('a' + i));
            }

            // We only need half of each character
            freq[i] /= 2;
        }

        int halfLen = n / 2;

        StringBuilder half = new StringBuilder();

        int matched = 0;

        // Try to match target's prefix
        while (matched < halfLen) {

            int c = target.charAt(matched) - 'a';

            if (freq[c] == 0) {
                break;
            }

            freq[c]--;
            half.append((char) ('a' + c));
            matched++;
        }

        int i = matched;

        // Backtrack and try a larger character
        while (i >= 0) {

            // Try to make the current position
            // greater than target
            if (i < halfLen) {

                int start = target.charAt(i) - 'a' + 1;

                for (int c = start; c < 26; c++) {

                    if (freq[c] == 0) {
                        continue;
                    }

                    freq[c]--;

                    // Build the smallest possible suffix
                    StringBuilder suffix = new StringBuilder();

                    for (int j = 0; j < 26; j++) {
                        for (int x = 0; x < freq[j]; x++) {
                            suffix.append((char) ('a' + j));
                        }
                    }

                    String left =
                        half.substring(0, i)
                        + (char) ('a' + c)
                        + suffix;

                    String candidate =
                        left
                        + middle
                        + new StringBuilder(left)
                            .reverse()
                            .toString();

                    // We need the smallest palindrome > target
                    if (candidate.compareTo(target) > 0) {
                        return candidate;
                    }

                    freq[c]++;
                }
            }

            // If the complete half matched target,
            // check whether it itself gives a valid answer
            if (i == halfLen) {

                String left = half.toString();

                String candidate =
                    left
                    + middle
                    + new StringBuilder(left)
                        .reverse()
                        .toString();

                if (candidate.compareTo(target) > 0) {
                    return candidate;
                }
            }

            // Backtrack
            i--;

            if (i >= 0) {

                int c = half.charAt(i) - 'a';

                freq[c]++;

                half.deleteCharAt(half.length() - 1);
            }
        }

        return "";
    }
}
