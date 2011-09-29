function update_side_saleoff()
{
  $.get("/sanpham/giamgia/ajax", function(data){
    $("#divSaleOff").html(data);
    setTimeout(update_side_saleoff, 3000);
  });
}

ddaccordion.init({
  headerclass: "expandablelevel1", //Shared CSS class name of headers group
  contentclass: "menucontentslevel1", //Shared CSS class name of contents group
  revealtype: "click", //Reveal content when user clicks or onmouseover the header? Valid value: "click", "clickgo", or "mouseover"
  mouseoverdelay: 200, //if revealtype="mouseover", set delay in milliseconds before header expands onMouseover
  collapseprev: false, //Collapse previous content (so only one open at any time)? true/false
  defaultexpanded: [0], //index of content(s) open by default [index1, index2, etc]. [] denotes no content
  onemustopen: false, //Specify whether at least one header should be open always (so never all headers closed)
  animatedefault: false, //Should contents open by default be animated into view?
  persiststate: true, //persist state of opened contents within browser session?
  toggleclass: ["headerlevel1unselected", "headerlevel1selected"], //Two CSS classes to be applied to the header when it's collapsed and expanded, respectively ["class1", "class2"]
  togglehtml: ["none", "", ""], //Additional HTML added to the header when it's collapsed and expanded, respectively  ["position", "html1", "html2"] (see docs)
  animatespeed: 500, //speed of animation: integer in milliseconds (ie: 200), or keywords "fast", "normal", or "slow"
  oninit:function(expandedindices){ //custom code to run when headers have initalized
    //do nothing
  },
  onopenclose:function(header, index, state, isuseractivated){ //custom code to run whenever a header is opened or closed
    //do nothing
  }
});

ddaccordion.init({
  headerclass: "expandablelevel2", //Shared CSS class name of headers group
  contentclass: "menucontentslevel2", //Shared CSS class name of contents group
  revealtype: "click", //Reveal content when user clicks or onmouseover the header? Valid value: "click", or "mouseover"
  mouseoverdelay: 200, //if revealtype="mouseover", set delay in milliseconds before header expands onMouseover
  collapseprev: false, //Collapse previous content (so only one open at any time)? true/false
  defaultexpanded: [], //index of content(s) open by default [index1, index2, etc]. [] denotes no content.
  onemustopen: false, //Specify whether at least one header should be open always (so never all headers closed)
  animatedefault: false, //Should contents open by default be animated into view?
  persiststate: true, //persist state of opened contents within browser session?
  toggleclass: ["headerlevel2unselected", "headerlevel2selected"], //Two CSS classes to be applied to the header when it's collapsed and expanded, respectively ["class1", "class2"]
  togglehtml: ["none", "", ""], //Additional HTML added to the header when it's collapsed and expanded, respectively  ["position", "html1", "html2"] (see docs)
  animatespeed: 500, //speed of animation: integer in milliseconds (ie: 200), or keywords "fast", "normal", or "slow"
  oninit:function(expandedindices){ //custom code to run when headers have initalized
    //do nothing
  },
  onopenclose:function(header, index, state, isuseractivated){ //custom code to run whenever a header is opened or closed
    //do nothing
  }
});

/*
$(document).ready(function(){
  $('a.agallery').lightBox();
});
*/
/*
$(document).ready(function() {
    $('#slides').cycle({
        // fx:     'scrollLeft,scrollDown,scrollRight,scrollUp,fade,zoom,blindX,blindY,blindZ,growX,growY,curtainX,curtainY',
        fx:     'fade',
        speed:   800,
        timeout: 4000,
        next:   '#next',
        prev:   '#prev'
    });
});
*/
$(document).ready(function() {
    $("#makeMeScrollable").smoothDivScroll({
        autoScroll: "onstart",
        autoScrollDirection: "backandforth",
        autoScrollStep: 1,
        autoScrollInterval: 15,
        startAtElementId: "startAtMe",
        visibleHotSpots: "always" });
});
function trim(str, chars) {
  return ltrim(rtrim(str, chars), chars);
}

function ltrim(str, chars) {
  chars = chars || "\\s";
  return str.replace(new RegExp("^[" + chars + "]+", "g"), "");
}

function rtrim(str, chars) {
  chars = chars || "\\s";
  return str.replace(new RegExp("[" + chars + "]+$", "g"), "");
}