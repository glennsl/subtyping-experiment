module Dom = {
  type node_ 'a;
  type node = node_ unit;
  type elementTag 'a;
  type element_ 'a = node_ (elementTag 'a);
  type element = element_ unit;
  type htmlElementTag;
  type htmlElement = element_ htmlElementTag;
  type documentTag 'a;
  type document_ 'a = node_ (documentTag 'a);
  type document = document_ unit;
  type htmlDocumentTag;
  type htmlDocument = document_ htmlDocumentTag;



  module Node = {
    external make : unit => node = "" [@@bs.val];

    external consume : node_ 'a => unit = "" [@@bs.val];
  };

  module Element = {
    external make : unit => element = "" [@@bs.val];

    external consume : element_ 'a => unit = "" [@@bs.val];

    external nextElement : element = "" [@@bs.send.pipe: element_ 'a];
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

Generates the error:

Error: This expression has type Dom.node = unit Dom.node_
       but an expression was expected of type
         'a Dom.element_ = 'a Dom.elementTag Dom.node_
       Type unit is not compatible with type 'a Dom.elementTag
*/

let htmlElement = Dom.HtmlElement.make ();
let _ = Dom.Node.consume htmlElement;

let next = Dom.Element.nextElement htmlElement;
/*
let _ = Dom.HtmlElement.consume next; /* this shouldn't typecheck */

Generates the error:

Error: This expression has type Dom.element = unit Dom.elementTag Dom.node_
       but an expression was expected of type
         Dom.htmlElement = Dom.htmlElementTag Dom.elementTag Dom.node_
       Type unit is not compatible with type Dom.htmlElementTag
*/

let _ = Dom.Element.consume next;
