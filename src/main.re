module Dom = {
  type node_ 'ext;
  type node 'ext = node_ 'ext;
  type element_ 'ext;
  type element 'ext = node (element_ 'ext);
  type htmlElement_;
  type htmlElement = element htmlElement_;
  type document_ 'ext;
  type document 'ext = node (document_ 'ext);
  type htmlDocument_;
  type htmlDocument = document htmlDocument_;

  module Node = {
    external make : unit => node unit = "" [@@bs.val];

    external consume : node 'ext => unit = "" [@@bs.val];
  };

  module Element = {
    external make : unit => element unit = "" [@@bs.val];

    external consume : element 'ext => unit = "" [@@bs.val];

    external nextElement : element unit = "" [@@bs.send.pipe: element 'ext];
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

Generates theerror:

Error: This expression has type unit Dom.node = unit Dom.node_
       but an expression was expected of type
         'a Dom.element = 'a Dom.element_ Dom.node_
       Type unit is not compatible with type 'a Dom.element_
*/

let htmlElement = Dom.HtmlElement.make ();
let _ = Dom.Node.consume htmlElement;

let next = Dom.Element.nextElement htmlElement;
/*
let _ = Dom.HtmlElement.consume next; /* this shouldn't typecheck */

Generates the error:

Error: This expression has type
         unit Dom.element = unit Dom.element_ Dom.node_
       but an expression was expected of type
         Dom.htmlElement = Dom.htmlElement_ Dom.element_ Dom.node_
       Type unit is not compatible with type Dom.htmlElement_
*/

let _ = Dom.Element.consume next;
