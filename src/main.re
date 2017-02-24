module Dom = {
  type node_like 'a;
  type node = node_like unit;
  type element_tag 'a;
  type element_like 'a = node_like (element_tag 'a);
  type element = element_like unit;
  type htmlElement_tag;
  type htmlElement = element_like htmlElement_tag;
  type document_tag 'a;
  type document_like 'a = node_like (document_tag 'a);
  type document = document_like unit;
  type htmlDocument_tag;
  type htmlDocument = document_like htmlDocument_tag;



  module Node = {
    external make : unit => node = "" [@@bs.val];

    external consume : node_like 'a => unit = "" [@@bs.val];
  };

  module Element = {
    external make : unit => element = "" [@@bs.val];

    external consume : element_like 'a => unit = "" [@@bs.val];

    external nextElement : element = "" [@@bs.send.pipe: element_like 'a];
  };

  module HtmlElement = {
    external make : unit => htmlElement = "" [@@bs.val];

    external consume : htmlElement => unit = "" [@@bs.val];
  };
};

let node = Dom.Node.make ();
let _ = Dom.Node.consume node;
/*
let _ = Dom.Element.consume node; /* this shouldn't typecheck */
*/
let htmlElement = Dom.HtmlElement.make ();
let _ = Dom.Node.consume htmlElement;

let next = Dom.Element.nextElement htmlElement;
/*
let _ = Dom.HtmlElement.consume next; /* this shouldn't typecheck */
*/
let _ = Dom.Element.consume next;
