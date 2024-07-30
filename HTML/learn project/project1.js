
document.getElementById("searchButton").addEventListener("click", function() {
    var searchText = document.getElementById("topic").value;
    if (searchText) {
        // Implement your search functionality here, for example:
        alert("Searching for: " + searchText);
        // Or you can redirect to a search results page:
        // window.location.href = "searchResultsPage.html?query=" + encodeURIComponent(searchText);
    } else {
        alert("Please enter a search term.");
    }
});
   