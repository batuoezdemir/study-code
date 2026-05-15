#ifndef SEARCH_ENGINE_HPP
#define SEARCH_ENGINE_HPP

#include <string>
class SearchEngine
{
    private:
    static constexpr int MAX_WEB_RESOURCES = 100;
    static int total_queries;
    WebResource web_resources[MAX_WEB_RESOURCES];
    int web_resource_count;

    SearchQuery current_query;

    WebResource current_search_results[MAX_WEB_RESOURCES];
    int current_search_result_count;
