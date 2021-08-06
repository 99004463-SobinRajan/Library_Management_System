# TEST PLAN:

| Sr No. | Module                           | Description                                                    | Input           | Expected Output          | Result |
|--------|----------------------------------|----------------------------------------------------------------|-----------------|--------------------------|--------|
| T01    | Add Book                         | Add Book to library                                            | 6, "Witcher:Blood of Elves", "Andrzej Sapkowski", "SuperNowa", 299, 223 | Book added to library | Pass |
| T02    | Remove Book                      | Remove Book from Library                                       | 1               | Book removed from library | Pass  |
| T03    | Find Book By ID                  | Find Book in Library                                           | 1               | Book Found                | Pass  |
| T04    | Find Book By Author              | Find Book in Library                                           | George RR Mrtin | Book/Books Found          | Pass  |
| T05    | Find Book By Author              | Find Book in Library                                           | Chetan Bhagat   | Book/Books Found          | Pass  |
| T06    | Find Average Price               | Find Average Price of Book in Library                          | Total Books     | 1089.6                    | Pass  |
| T07    | Find Book With Max Pages         | Find Book with Max pages present in Library                    | Total Books     | 948                       | Pass  |
| T08    | Find Book With Min Pages         | Find Book with Min pages present in Library                    |  Total Books    | 599                       | Pass  |
| T09    | Find Avereage Price By Publisher | Find Average Price of books of publisher                       | wiley           | 1999                      | Pass  |
| T10    | Find Min Price by Publisher      | Find Book with Min Price present in Library                    | Harper Voyager  | 599                       | Pass  |
| T11    | Count Book In Range              | Count the number of book present within range                  | 0, 600          | 1                         | Pass  |
| T12    | Count Book in Less Range         | Count the number of book present in less than the given number | 700             | 3                         | Pass  |


