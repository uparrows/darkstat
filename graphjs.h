/* this file was automatically generated */
static char graph_js[] =
"/* darkstat 3\n"
" * copyright (c) 2006-2008 Emil Mikulic.\n"
" *\n"
" * graph.js: graph renderer\n"
" *\n"
" * You may use, modify and redistribute this file under the terms of the\n"
" * GNU General Public License version 2. (see COPYING.GPL)\n"
" *\n"
" * At some point, this script worked correctly in:\n"
" *  - Firefox 1.5.0.4, 2.0.0.1, 3.0\n"
" *  - IE 6.0\n"
" *  - Opera 8.53, 9.50\n"
" *  - Konqueror 3.5.9, 4.0.80, 4.0.83\n"
" *\n"
" * Consumer needs to supply the following variables:\n"
" *  - graph_width\n"
" *  - graph_height\n"
" *  - bar_gap\n"
" *\n"
" *  - graphs [ {id, name, title, bar_secs} ]\n"
" *  - graphs_uri\n"
" *\n"
" *  - window.onload = graphs_init\n"
" */\n"
"\n"
"function killChildren(elem) {\n"
" while (elem.childNodes.length > 0)\n"
"  elem.removeChild( elem.childNodes.item(0) );\n"
"}\n"
"\n"
"function setClass(elem, c) {\n"
" elem.setAttribute(\"class\", c);\n"
" elem.setAttribute(\"className\", c); /* for MSIE */\n"
"}\n"
"\n"
"function setStyle(elem, s) {\n"
" elem.setAttribute(\"style\", s);\n"
" elem.style.cssText = s; /* for MSIE */\n"
"}\n"
"\n"
"function makeElemClass(e, c) {\n"
" var r = document.createElement(e);\n"
" setClass(r, c);\n"
" return r;\n"
"}\n"
"\n"
"function makeClear() {\n"
" var r = document.createElement(\"div\");\n"
" setStyle(r, \"clear:both\");\n"
" return r;\n"
"}\n"
"\n"
"function thousands(n) {\n"
" var s = String(n);\n"
" var out = \"\";\n"
" while (s.length > 3) {\n"
"  out = \",\" + s.substr(s.length - 3, 3) + out;\n"
"  s = s.substr(0, s.length - 3);\n"
" }\n"
" return s+out;\n"
"}\n"
"\n"
"function fkbps(bps) {\n"
" bps /= 1024;\n"
" return bps.toFixed(1);\n"
"}\n"
"\n"
"function kbps(bps) {\n"
" bps /= 1024;\n"
" if (bps < 1) return bps.toPrecision(2);\n"
" else return bps.toFixed(1);\n"
"}\n"
"\n"
"function min(a,b) { return (a<b)?a:b; }\n"
"function max(a,b) { return (a>b)?a:b; }\n"
"\n"
"var xh, autoreload=false;\n"
"\n"
"function graphs_init() {\n"
" var gr = document.getElementById(\"graphs\");\n"
"\n"
" /* update message */\n"
" var msg = document.createElement(\"div\");\n"
" msg.appendChild(document.createTextNode(\"图表正在加载...\"));\n"
" msg.appendChild(document.createElement(\"br\"));\n"
" msg.appendChild(document.createElement(\"br\"));\n"
" killChildren(gr);\n"
" gr.appendChild(msg);\n"
" graphs.msg = msg;\n"
"\n"
" for (var i=0; i<graphs.length; i++) {\n"
"  var g =  makeElemClass(\"div\", \"outergraph\");\n"
"  gr.appendChild(g);\n"
"  graphs[i].graph = g;\n"
"  if (i % 2 == 1) gr.appendChild(makeClear());\n"
" }\n"
"\n"
" /* create buttons */\n"
" var b_reload = document.createElement(\"a\");\n"
" b_reload.setAttribute(\"id\", \"graph_reload\");\n"
" b_reload.setAttribute(\"href\", \"javascript:graph_reload()\");\n"
" b_reload.appendChild(document.createTextNode(\"重载图表\"));\n"
"\n"
" var b_autoreload = document.createElement(\"a\");\n"
" b_autoreload.setAttribute(\"id\", \"graph_autoreload\");\n"
" b_autoreload.setAttribute(\"href\", \"javascript:graph_autoreload()\");\n"
" b_autoreload.appendChild(document.createTextNode(\"关\"));\n"
"\n"
" var b = document.createElement(\"div\");\n"
" b.appendChild(b_reload);\n"
" b.appendChild(document.createTextNode(\" - 自动刷新: \"));\n"
" b.appendChild(b_autoreload);\n"
" gr.appendChild(b);\n"
"\n"
" graph_reload();\n"
"}\n"
"\n"
"function graph_reload() {\n"
" if (!autoreload)\n"
"  document.getElementById(\"graph_reload\").innerHTML = \"加载...\";\n"
" xh = (window.ActiveXObject)\n"
"  ? new ActiveXObject(\"Microsoft.XMLHTTP\")\n"
"  : new XMLHttpRequest();\n"
" var asyncFlag = true;\n"
" xh.open(\"GET\", graphs_uri, asyncFlag);\n"
" // try to nerf caching:\n"
" xh.setRequestHeader(\"If-Modified-Since\", \"Sat, 1 Jan 2000 00:00:00 GMT\");\n"
" xh.onreadystatechange = poll;\n"
" xh.send(null);\n"
"}\n"
"\n"
"function graph_autoreload() {\n"
" // toggle\n"
" autoreload = !autoreload;\n"
" document.getElementById(\"graph_autoreload\").innerHTML =\n"
"  autoreload ? \"开\" : \"关\";\n"
" if (autoreload) reload_loop();\n"
"}\n"
"\n"
"function reload_loop() {\n"
" if (autoreload) {\n"
"  graph_reload();\n"
"  setTimeout(\"reload_loop()\", 1000);\n"
" }\n"
"}\n"
"\n"
"function poll() {\n"
" var STATE_COMPLETE = 4;\n"
" if (xh && xh.readyState == STATE_COMPLETE) {\n"
"  for (var i=0; i<graphs.length; i++)\n"
"  {\n"
"   g = xh.responseXML.getElementsByTagName(graphs[i].name);\n"
"   buildGraph(graphs[i].graph, graphs[i].title, graphs[i].bar_secs,\n"
"    g[0].getElementsByTagName(\"e\"));\n"
"  }\n"
"  document.getElementById(\"graph_reload\").innerHTML = \"重载图表\";\n"
"  killChildren(graphs.msg);\n"
"  head = xh.responseXML.childNodes[0];\n"
"  for (var n in {\"tb\":0, \"tp\":0, \"pc\":0, \"pd\":0})\n"
"   document.getElementById(n).innerHTML = thousands(head.getAttribute(n));\n"
"  document.getElementById(\"rf\").innerHTML = head.getAttribute(\"rf\");\n"
" }\n"
"}\n"
"\n"
"function addBar(graph, title, barclass, width, height, left, bottom) {\n"
" if (height == 0) return; /* not visible */\n"
" var bar = makeElemClass(\"div\", barclass);\n"
" bar.setAttribute(\"title\", title);\n"
" setStyle(bar,\n"
"  \"width:\"+width+\"px; \"+\n"
"  \"height:\"+height+\"px; \"+\n"
"  \"position: absolute; \"+\n"
"  \"left:\"+left+\"px; \"+\n"
"  \"bottom:\"+bottom+\"px;\");\n"
" graph.appendChild(bar);\n"
"}\n"
"\n"
"function buildGraph(graph, title, bar_secs, elems) {\n"
" var total_max = 0;\n"
" var data = []; /* list of [in, out] */\n"
" for (var i=0; i<elems.length; i++) {\n"
"   var elem = elems.item(i);\n"
"   var b_pos = Number( elem.getAttribute(\"p\") );\n"
"   var b_in = Number( elem.getAttribute(\"i\") );\n"
"   var b_out = Number( elem.getAttribute(\"o\") );\n"
"   var b_total = b_in + b_out;\n"
"/* FIXME: what happens when a bar's value is >4G? */\n"
"   if (b_total > total_max)\n"
"    total_max = b_total;\n"
"   data.push( [b_pos, b_in, b_out] );\n"
" }\n"
"\n"
" var igraph = makeElemClass(\"div\", \"graph\"); // inner graph\n"
" setStyle(igraph,\n"
"  \"width:\"+graph_width+\"px; \"+\n"
"  \"height:\"+graph_height+\"px; \"+\n"
"  \"position:relative;\");\n"
"\n"
" var nbars = data.length;\n"
" var b_width = (graph_width - bar_gap * (nbars-1)) / nbars;\n"
" var next_xofs = 0;\n"
"\n"
" var min_i = 0, min_o = 0,\n"
"     max_i = 0, max_o = 0,\n"
"     tot_i = 0, tot_o = 0;\n"
"\n"
" for (var i=0; i<nbars; i++) {\n"
"  var b_p = data[i][0];\n"
"  var b_i = data[i][1];\n"
"  var b_o = data[i][2];\n"
"\n"
"  if (b_i>0) { if (min_i == 0) min_i = b_i; else min_i = min(min_i, b_i); }\n"
"  max_i = max(max_i, b_i);\n"
"  tot_i += b_i;\n"
"\n"
"  if (b_o>0) { if (min_o == 0) min_o = b_o; else min_o = min(min_o, b_o); }\n"
"  max_o = max(max_o, b_o);\n"
"  tot_o += b_o;\n"
"\n"
"  var xofs = next_xofs;\n"
"\n"
"  next_xofs = Math.round((b_width + bar_gap) * (i+1));\n"
"  var curr_w = next_xofs - xofs - bar_gap;\n"
"\n"
"  var h_i = Math.round( b_i * graph_height / total_max );\n"
"  var h_o = Math.round( b_o * graph_height / total_max );\n"
"\n"
"  var label = b_p+\": \"+\n"
"   thousands(b_i)+\" bytes in, \"+\n"
"   thousands(b_o)+\" bytes out | \"+\n"
"   kbps(b_i/bar_secs)+\" KB/s in, \"+\n"
"   kbps(b_o/bar_secs)+\" KB/s out\";\n"
"\n"
"  addBar(igraph, label, \"bar_in\", curr_w, h_i, xofs, 0);\n"
"  addBar(igraph, label, \"bar_out\", curr_w, h_o, xofs, h_i);\n"
" }\n"
"\n"
" function legendRow(dir_str, minb, avgb, maxb) {\n"
"  function makeTD(c, str) {\n"
"   var r = makeElemClass(\"td\", c);\n"
"   r.appendChild(document.createTextNode(str));\n"
"   return r;\n"
"  }\n"
"  function addToRow(row, type_str, bytes, trail) {\n"
"   row.appendChild( makeTD(\"type\", type_str) );\n"
"   row.appendChild( makeTD(\"rate\", fkbps(bytes/bar_secs)+\" KB/s\"+trail) );\n"
"  }\n"
"  var row = document.createElement(\"tr\");\n"
"  row.appendChild( makeTD(\"dir\", dir_str) );\n"
"  var cell = makeElemClass(\"td\", \"swatch\");\n"
"  var swatch = makeElemClass(\"div\", \"bar_\"+dir_str);\n"
"  setStyle(swatch, \"width:6px; height:6px;\");\n"
"  cell.appendChild(swatch);\n"
"  row.appendChild(cell);\n"
"  addToRow(row, \"最小:\", minb, \",\");\n"
"  addToRow(row, \"平均:\", avgb, \",\");\n"
"  addToRow(row, \"最大:\", maxb, \"\");\n"
"  return row;\n"
" }\n"
"\n"
" var glegend = makeElemClass(\"div\", \"legend\");\n"
" var avg_i = tot_i / nbars,\n"
"     avg_o = tot_o / nbars;\n"
" var tbl = document.createElement(\"table\");\n"
" var tb = document.createElement(\"tbody\"); /* for MSIE */\n"
" tb.appendChild( legendRow(\"入站\", min_i, avg_i, max_i) );\n"
" tb.appendChild( legendRow(\"出站\", min_o, avg_o, max_o) );\n"
" tbl.appendChild(tb);\n"
" glegend.appendChild(tbl);\n"
" setStyle(glegend, \"width:\"+graph_width+\"px;\");\n"
"\n"
" var gtitle = makeElemClass(\"div\", \"graphtitle\");\n"
" setStyle(gtitle, \"width:\"+graph_width+\"px;\");\n"
" gtitle.appendChild(document.createTextNode(title));\n"
"\n"
" killChildren(graph);\n"
" graph.appendChild(igraph);\n"
" graph.appendChild(glegend);\n"
" graph.appendChild(gtitle);\n"
"}\n";
static const size_t graph_js_len = sizeof(graph_js) - 1;