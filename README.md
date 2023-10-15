# longest-compounded-word
<h1>
 Algorithm:
</h1>
<h2>
 The program uses a Trie data structure to efficiently check if a word can be formed by concatenating other words. It follows these steps:
</h2>
<p>
 1.Read the list of words from the input file and insert them into a Trie. <br>

 2.Sort the list of words in descending order of length.<br>

 3.For each word in the sorted list, check if it is a compound word by traversing the Trie.<br>
 
 4.Store compound words in a set.<br>

 5.Find the longest and second-longest compound words from the set.
</p>
